# SDSC HPC User Training:  Spring 2020
## WEEK 4: 01/31/2020

## TOPIC:  GPU accelerated computing with CUDA Python	
**Presented By:**  Abe Stern, NVIDIA

### Related Reading and Presentations

[Numba](http://numba.pydata.org/) supports CUDA GPU programming by directly 
compiling a subset of Python code into CUDA kernels and device functions 
following the CUDA execution model.  

In the provided notebooks, a problem is introduced and mostly implemented in 
Numba.  As an exercise, complete the missing lines of code to successfully 
compute the result.  

## WEEK 4 TASKS

### TASK 1

In this exercise we will design a CUDA kernel to compute the value of Pi 
via Monte Carlo.  The concepts of writing and invoking CUDA kernels in 
Numba are introduced.

* [computing_pi.ipynb](./computing_pi.ipynb)
* [computing_pi_solution](./computing_pi_solution.ipynb)

### TASK 2

Here, we will compute a distance matrix for a synthetic dataset of 
3-D molecular geometries.  We will learn how to leverage higher-dimensional
CUDA thread-block hierarchies.

* [distance_matrix.ipynb](./distance_matrix.ipynb)
* [distance_matrix_solution](./distance_matrix_solution.ipynb)

### TASK 3

In this exercise, we will explore GPU Ufuncs which are simple to write, invoke, 
and are compatible with Numpy Ufuncs.  We will learn how to write a simple GPU 
Ufunc to compute the law of cosines.

* [law_of_cosines.ipynb](./law_of_cosines.ipynb)
* [law_of_cosines_solution.ipynb](./law_of_cosines_solution.ipynb)
