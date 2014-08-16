/*
    Copyright � 2014, The AROS Development Team. All rights reserved.
    $Id$

    Desc: PCI XHCI USB host controller
    Lang: English
*/

#ifdef DEBUG
#undef DEBUG
#endif
#define DEBUG 1

#include <aros/io.h>
#include <aros/debug.h>
#include <aros/macros.h>
#include <aros/asmcall.h>
#include <aros/symbolsets.h>

#include <proto/oop.h>
#include <proto/exec.h>
#include <proto/stdc.h>
#include <proto/arossupport.h>

#include <devices/usb.h>
#include <devices/usb_hub.h>
#include <devices/newstyle.h>
#include <devices/usbhardware.h>

#include <asm/io.h>
#include <inttypes.h>

#include <hidd/pci.h>
#include <hidd/hidd.h>

#include "pcixhci_intern.h"

#include "pcixhci_controller.h"

#include LC_LIBDEFS_FILE

#define PCIXHCIBase unit->pcixhcibase

/*
    We get called only once when the driver inits
    We own the controller until our driver expunges so we assume that nobody messes with our stuff...
*/
BOOL PCIXHCI_HCInit(struct PCIXHCIUnit *unit) {
    //mybug(0, ("[PCIXHCI] PCIXHCI_HCInit: Entering function\n"));

    /* Our unit is in suspended state until it is reset */
    unit->state = UHSF_SUSPENDED;

    snprintf(unit->name, 255, "PCIXHCI[%02x:%02x.%01x]", (UBYTE)unit->hc.bus, (UBYTE)unit->hc.dev, (UBYTE)unit->hc.sub);
    unit->node.ln_Name = (STRPTR)&unit->name;

    /* Store opregbase */
    unit->hc.opregbase = (APTR) ((ULONG) (unit->hc.capregbase) + capreg_readb(XHCI_CAPLENGTH));

    mybug_unit(-1, ("unit node name %s\n", unit->node.ln_Name));
    mybug_unit(-1, ("pcidevice  = %p\n",   unit->hc.pcidevice));
    mybug_unit(-1, ("pcidriver  = %p\n",   unit->hc.pcidriver));
    mybug_unit(-1, ("bus        = %x\n",   unit->hc.bus));
    mybug_unit(-1, ("dev        = %x\n",   unit->hc.dev));
    mybug_unit(-1, ("sub        = %x\n",   unit->hc.sub));
    mybug_unit(-1, ("intline    = %d\n",   unit->hc.intline));
    mybug_unit(-1, ("capregbase = %p\n",   unit->hc.capregbase));
    mybug_unit(-1, ("opregbase  = %p\n",   unit->hc.opregbase));

    struct TagItem pciActivateMemAndBusmaster[] = {
            { aHidd_PCIDevice_isIO,     FALSE },
            { aHidd_PCIDevice_isMEM,    TRUE },
            { aHidd_PCIDevice_isMaster, TRUE },
            { TAG_DONE, 0UL },
    };

    OOP_SetAttrs(unit->hc.pcidevice, (struct TagItem *)pciActivateMemAndBusmaster);

    /* Get the host controller from BIOS if possible */

    /* Init the port list but do not fill it */
    NEWLIST(&unit->roothub.port_list);

    return TRUE;
}


/*
    We get called everytime the driver is trying to get online
    We make use of it by also filling the port list of our unit,
    that way toggling unit offline and online may give different results for ports after reset
*/
BOOL PCIXHCI_HCReset(struct PCIXHCIUnit *unit) {
    mybug_unit(0, ("Entering function\n"));

    struct PCIXHCIPort *port = NULL;

    ULONG portnum = 0;

    /* our unit is in reset state until the higher level usb reset is called */
    unit->state = UHSF_RESET;




    /* (Re)build the port list of our unit */
    ForeachNode(&unit->roothub.port_list, port) {
        mybug_unit(-1, ("Deleting port %d named %s\n", port->number, port->name));
        REMOVE(port);
        FreeVec(port);
    }

    port = AllocVec(sizeof(struct PCIXHCIPort), MEMF_ANY|MEMF_CLEAR);
    if(port == NULL) {
        mybug_unit(-1, ("Failed to create new port structure\n"));
        return FALSE;
    } else {
        port->node.ln_Type = NT_USER;
        snprintf(port->name, 255, "PCIXHCI[%02x:%02x.%01x] port %d", (UBYTE)unit->hc.bus, (UBYTE)unit->hc.dev, (UBYTE)unit->hc.sub, ++portnum);
        port->node.ln_Name = (STRPTR)&port->name;
        port->number = portnum;
        AddTail(&unit->roothub.port_list,(struct Node *)port);

        mybug_unit(-1, ("Created new port numbered %d at %p\n",port->number, port));
        mybug_unit(-1, ("Port node name %s\n", port->node.ln_Name));
    }

    return TRUE;
}









