# AROS Git Repository

> This is the main repository for active development of the AROS Operating System.
> The repository contains the main Operating System components, SDK and Build System.

## Nightly Test Builds

* Builds are currently not downloadable (TODO), and only done to check if the targets compile.
* Builds are configured to use gcc 9.1.0
* The main AROS target and distfiles are built for each arch.
* Builds are made using the azure-pipelines.yml file found in the azure-pipelines branch. Further details can be found in that file.

| BUILD Arch | Status |
| --- | --- |
| linux-i386 | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-linux-i386?branchName=azure-pipelines)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=1&branchName=azure-pipelines) |
| linux-x86_64 | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-linux-x86_64?branchName=azure-pipelines)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=1&branchName=azure-pipelines) |
| pc-i386 | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-pc-i386?branchName=azure-pipelines)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=1&branchName=azure-pipelines) |
| pc-x86_64 | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-pc-x86_64?branchName=azure-pipelines)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=1&branchName=azure-pipelines) |
| pc-x86_64-smp | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-pc-x86_64-smp?branchName=azure-pipelines)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=7&branchName=azure-pipelines) |
| amiga-m68k | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-amiga-m68k?branchName=azure-pipelines)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=1&branchName=azure-pipelines) |
| raspi-armhf | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-raspi-armhf?branchName=azure-pipelines)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=1&branchName=azure-pipelines) |
| sam440-ppc | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-sam440-ppc?branchName=azure-pipelines)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=1&branchName=azure-pipelines) |

## License

This project is licensed under the APL License - see the [LICENSE](LICENSE) file for details

## Acknowledgments

AROS contains parts built upon external components - see the [ACKNOWLEDGEMENTS](ACKNOWLEDGEMENTS) file for details

