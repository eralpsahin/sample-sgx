# SGX Project Template

This template is based on the hello-enclave app [hello-enclave](https://github.com/digawp/hello-enclave).

## Prerequirements
- To install Intel SGX, clone the project and follow the steps from [official repository](https://github.com/intel/linux-sgx#install-the-intelr-sgx-sdk-1).
- SGX **requires some environment variables**, need to `source` the environment before compiling an SGX project. `source ${sgx-sdk-install-path}/environment` I suggest adding the command to the startup script of your shell.
- Now you are ready to compile this project.

## Compile - Execution
1. `make` to compile the project.
2. The default make rule creates `app` file that can be executed.

## Description
- Project is compiled in [Simulation Mode](https://software.intel.com/en-us/blogs/2016/05/30/usage-of-simulation-mode-in-sgx-enhanced-application). There is no hardware requirement.
- The untrusted domain is `App/App.cpp`
- The trusted domain (*Enclave*) is ` Enclave/Enclave.app`
- The Enclave Definition (*EDL*) file is `Enclave/Enclave.edl`
- For basic projects, modifying `App.cpp`, `Enclave.cpp` and `Enclave.edl` file is enough.
- `Enclave.h` can be used for defining user defined types etc.

### Additional Information
- The `Enclave.h` in the root folder is used when a user defined type such as `typedef` and `struct` needs to be defined for edger8r. For that the header file gets included in the EDL file.
- For SGX, the untrusted domain needs to initalize an enclave. That is handled by the small helper `App/sgx_utils` library.
- Edger8r generally emits an error if there is a syntactic or semantic problem with the EDL file. 