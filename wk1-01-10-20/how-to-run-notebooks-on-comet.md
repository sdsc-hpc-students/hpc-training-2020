# HPC Training:  Spring 2019
## WEEK 10:  06/07/19	

## TOPICS: 
### 1.  Jupyter Notebooks
Using Jupyter Notebooks (by Mary Thomas): see below

Link to Bailey Passmores GitHub repos: [github.com/bailatrix/repositories](github.com/bailatrix/repositories)
  * PharmaPy: Reading csv files. Almost no data cleaning. Lots of detailed graph building with matplotlib. 
  * WeatherPy: Uses openweathermap API to import data. Minimal data cleaning and formatting in pandas. 
  * London-Traffic-Trends: Lots of data cleaning in pandas and simple use of matplotlib for visualizations. 
Note: Some of the notebooks don't load on the first try, but they are all there and working!

### 2.  Overview of ML/DL frameworks -TensorFlow, PyTorch, and Horovod
* [Presentation on Machine learning (Horovod):](https://github.com/sdsc-hpc-students/hpc-training-spring2019/blob/master/wk10-06-07-19/DL_TensorFlow_PyTorch_Horovod.pdf) 

PRESENTED BY: Dr. Mahidhar Tatineni

## TASKS:
### 1. Using Jupyter Notebooks (by Mary Thomas): 
Learn how to run/edit a jupyter notebook on comet using Python notebooks 

* Log onto comet.sdsc.edu  
```
ssh -Y -l <username> comet.sdsc.edu
```

* create a test directory, or ```cd``` into one you have already created
* Clone this repository (developed by Bob Sinkovits):   [https://github.com/sinkovit/PythonSeries](https://github.com/sinkovit/PythonSeries)
```
git clone git@github.com:sinkovit/PythonSeries.git
```

Get an interactive node:
```
srun --pty --nodes=1 --ntasks-per-node=24 -p compute -t 02:00:00 --wait 0 /bin/bash
srun: job 24000544 queued and waiting for resources
srun: job 24000544 has been allocated resources
[mthomas@comet-18-29:~/hpctrain/python/PythonSeries] 
```
Wait for your node to be allocated.
Load the singularity module that knows about jupyter notebooks and get an interactive shell
```
module load singularity
singularity shell /share/apps/gpu/singularity/sdsc_ubuntu_tf1.1_keras_R.img
```
Check out the Readme.md file, it will explaing what is in the different notebooks.
Launch the Jupyter Notebook application. 
Note: this application will be running on comet, and you will be given a URL which will connect your local web browser the interactive comet session:
```
ipython notebook --no-browser --ip=`/bin/hostname`
```
This will give you an address which has localhost in it and a token. Something
like:
```
http://comet-14-0-4:8888/?token=xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
```
You can then paste it into your browser. You will see a running Jupyter
notebook and a listing of the notebooks in your directory. From there everything should be working as a regular notebook.
Note: This token is your auth so don't email/send it around. It will go away when you stop the notebook. 

To learn about Python, run the ```Python basics.ipynb```   notebook.
To see an example of remote visualization, run the  ```Matplotlib.ipynb```  notebook!



### 2.  Machine Learning examples:
Try one of the MINST example from Mahidhar's presentation. See slide 42. 
First, create a directory in week10 to put the codes into (e.g. mach.learn)
Copy the directory below into your ```mach.learn``` directory:
```
cp -R /share/apps/examples/SCC/ML_Tensorflow .
```
You will see a jupyter notebook in the directory:  
```
[mthomas@comet-ln2:~/hpctrain/mach.learn/ML_Tensorflow] ls -al 
total 4072
drwxr-xr-x 2 mthomas use300       8 Jun 12 20:38 .
drwxr-xr-x 3 mthomas use300       3 Jun 12 20:38 ..
-rw-r--r-- 1 mthomas use300   41066 Jun 12 20:38 LabMNIST_Final.ipynb
-rw-r--r-- 1 mthomas use300    3416 Jun 12 20:38 LabMNIST_v1_py3.py
-rw-r--r-- 1 mthomas use300 7840080 Jun 12 20:38 X_test.npy
-rw-r--r-- 1 mthomas use300 3920080 Jun 12 20:38 X_train5k.npy
-rw-r--r-- 1 mthomas use300   10080 Jun 12 20:38 Y_test.npy
-rw-r--r-- 1 mthomas use300    5080 Jun 12 20:38 Y_train5k.npy
```
Follow the directions in Task 1, and grab an interactive node.
Paste the URL into the local browser. Once you see the Jypyter notebook, 
click on the ```LabMNIST_Final.ipynb``` file.
When the browser opens, run the notebook in steps so you can see the machine learning develop.

You can make the following changes, to see how the filter efficiency and effectiveness are impacted: does the code take longer? does it have better resolution?
* modify the filter size: 2x2, 3x3, 5x5, ... 
* change the number of layers: 8, 12, 16, 24 
* change the back propagation algorithm: currently set to stochastic gradient descent

