# SDSC HPC User Training
 
## Running Jupyter Notebooks On Comet (by Mary Thomas): 
Learn how to run/edit a jupyter notebook on comet using Python notebooks 

### Log onto comet.sdsc.edu  

```
ssh -l <username> comet.sdsc.edu
```

### Install Jupyter Notebook material
* If you don't have any notebooks installed on the system, clone this repository (developed by Bob Sinkovits):   [https://github.com/sinkovit/PythonSeries](https://github.com/sinkovit/PythonSeries)
```
git clone git@github.com:sinkovit/PythonSeries.git
```

### Obtain an interactive node:
```
srun --pty --nodes=1 --ntasks-per-node=24 -p debug -t 00:00:30 --wait 0 /bin/bash
srun: job 24000544 queued and waiting for resources
srun: job 24000544 has been allocated resources
[mthomas@comet-18-29:~/hpctrain/python/PythonSeries] 
```
Wait for your node to be allocated. Once you have your interactive node (you will know that because your user prompt will change), you need to load in an environment that knows about Jupyter Notebooks. You can do this two ways:
#### Install the Anaconda software -- see [https://www.anaconda.com/](https://www.anaconda.com/)
* Anaconda is free, and easy to install: [https://www.anaconda.com/distribution/](https://www.anaconda.com/distribution/)
* You will install it locally in your home directory, and you might need to add some configuration lines into your .bashrc file.
* Here is an example of my .bashrc file:

```
# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$('/home/mthomas/miniconda3/bin/conda' 'shell.bash' 'hook' 2> /dev/null)"
if [ $? -eq 0 ]; then
    eval "$__conda_setup"
else
    if [ -f "/home/mthomas/miniconda3/etc/profile.d/conda.sh" ]; then
        . "/home/mthomas/miniconda3/etc/profile.d/conda.sh"
    else
        export PATH="/home/mthomas/miniconda3/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda initialize <<<
```

#### Launch an environment that already knows about Jupyter Notebooks.
On Comet, we support the use of Singularity containers [https://sylabs.io/singularity/](https://sylabs.io/singularity/).
   * From the website: "Singularity is a container platform. It allows you to create and run containers that package up pieces of software in a way that is portable and reproducible. You can build a container using Singularity on your laptop, and then run it on many of the largest HPC clusters in the world, local university or company clusters, a single server, in the cloud, or on a workstation down the hall. Your container is a single file, and you don’t have to worry about how to install all the software you need on each different operating system and system."
   * SIF™ (Singularity Image Format) is a single executable file based container image, cryptographically signed, auditable, secure, and easy to move using existing data mobility paradigms
Load the singularity module that knows about jupyter notebooks.


You can find a list of SDSC supported Comet images here:
```
[comet-ln2:/share/apps/compute/singularity/images] pwd
/share/apps/compute/singularity/images(base) 
[omet-ln2:/share/apps/compute/singularity/images] ls -al
total 44
drwxr-sr-x 11 mkandes use300 4096 Dec  4 13:02 .
drwxr-sr-x  3 mkandes use300 4096 Dec  4 08:34 ..
drwxr-sr-x  2 mkandes use300 4096 Feb 11 17:05 centos
drwxr-sr-x  2 mkandes use300 4096 Dec  4 08:47 jupyter
drwxr-sr-x  2 mkandes use300 4096 Dec  4 08:53 keras
drwxr-sr-x  2 mkandes use300 4096 Jan  9 16:00 meep
drwxr-sr-x  2 mkandes use300 4096 Dec  4 12:38 mxnet
drwxr-sr-x  2 mkandes use300 4096 Mar  3 11:51 pytorch
drwxr-sr-x  2 mkandes use300 4096 Dec  4 13:00 tensorflow
drwxr-sr-x  2 mkandes use300 4096 Dec  4 13:03 theano
drwxr-sr-x  2 mkandes use300 4096 Feb 28 11:22 ubuntu
```

Update:  03/02/2020:: Use the newest version from the pytorch or tensorflow directories.
```
module load singularity
singularity shell /share/apps/compute/singularity/images/sdsc_ubuntu_tf1.1_keras_R.img
```

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


