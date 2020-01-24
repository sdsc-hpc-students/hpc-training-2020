# SDSC HPC User Training:  Spring 2020
**WEEK 3:** 01/24/2020

## TOPIC:  CUDA/GPU Computing
**Presented By:** [Andreas Goetz, SDSC](https://hpc-students.sdsc.edu/instr_bios/andreas_goetz.html) (agoetz  at  sdsc.edu)

### READING AND PRESENTATIONS:

Source code and Lecture Slides:

* [gpu-code-examples.tar.gz](gpu-code-examples.tar.gz)
* [sdsc-scc-gpu-computing-2020-01-24.pdf](sdsc-scc-gpu-computing-2020-01-24.pdf)


## WEEK 3 TASKS:
### TASK 1:  Using GPU nodes  
    Download and `untar` the gpu code file; 
    `cd` into the `gpu-code-examples` directory

```
% tar xvf gpu-code-examples.tar.gz
% cd gpu-code-examples
```
See the README.md file in the tarfile directory and
follow instructions on "How to use Comet's GPU nodes"


# Obtain interactive shared GPU node on SDSC Comet 
`getgpu`

The command below will launch the command

```
srun -t 00:30:00 --partition=gpu-shared --nodes=1 --ntasks-per-node=7 \
     --gres=gpu:p100:1 --reservation=sccgpures --pty --wait=0 /bin/bash
```

It may take some time to get the interactive node.

### TASKS 2 and 3 begin in the section called:
*"Simple code samples accompanying slides"*

Change to directory cuda-samples, compile with 
```
nvcc example.cu -o example.x
```

### TASK 2:  cd into the GPU code directory: 
```
% cd gpu-code-examples/cuda-samples
```

See the README.md files for instructions.
Run the following examples
 
	- hello_world
	- addition


### TASK 3:  cd into the OpenACC code directory:
```
% cd gpu-code-examples/openacc-samples
```
See the README.md file for instructions.

Compile C code with OpenACC pragmas with 
```
pgcc example.c -o example.x -acc -Minfo=accel
```

Compile and run the following example: 
``` 
	 - saxpy
```	 
The more ambitious are free to reproduce timings for the `laplace-2d` example (see README.md file)
