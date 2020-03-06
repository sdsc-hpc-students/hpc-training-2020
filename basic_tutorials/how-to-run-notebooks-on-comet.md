# SDSC HPC User Training
 
## 1. Running Jupyter Notebooks On Comet (by Mary Thomas): 
Learn how to run/edit a jupyter notebook on comet using Python notebooks 

* Log onto comet.sdsc.edu  
```
ssh -l <username> comet.sdsc.edu
```

* create a test directory, or ```cd``` into one you have already created
* Clone this repository (developed by Bob Sinkovits):   [https://github.com/sinkovit/PythonSeries](https://github.com/sinkovit/PythonSeries)
```
git clone git@github.com:sinkovit/PythonSeries.git
```

Get an interactive node:
```
srun --pty --nodes=1 --ntasks-per-node=24 -p debug -t 00:00:30 --wait 0 /bin/bash
srun: job 24000544 queued and waiting for resources
srun: job 24000544 has been allocated resources
[mthomas@comet-18-29:~/hpctrain/python/PythonSeries] 
```
Wait for your node to be allocated. Once you have your interactive node (you will know that because your user prompt will change), you need to load in an environment that knows about Jupyter Notebooks. You can do this two ways:
* Install the Anaconda software -- see []()
* Launch an environment that already knows about Jupyter Notebooks.
On Comet, we support the use of Singularity containers [https://sylabs.io/singularity/](https://sylabs.io/singularity/).
   * From the website: "Singularity is a container platform. It allows you to create and run containers that package up pieces of software in a way that is portable and reproducible. You can build a container using Singularity on your laptop, and then run it on many of the largest HPC clusters in the world, local university or company clusters, a single server, in the cloud, or on a workstation down the hall. Your container is a single file, and you don’t have to worry about how to install all the software you need on each different operating system and system."
   * SIF™ (Singularity Image Format) is a single executable file based container image, cryptographically signed, auditable, secure, and easy to move using existing data mobility paradigms
Load the singularity module that knows about jupyter notebooks.


You can find a list of SDSC supported Comet images here:
```
/share/apps/compute/singularity/images
```
Use the newest version from the pytorch or tensorflow directories.
```
module load singularity
singularity shell /share/apps/compute/singularity/images/sdsc_ubuntu_tf1.1_keras_R.img
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


