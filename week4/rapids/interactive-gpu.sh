srun --account=use300 --partition=gpu-shared --nodes=1 --ntasks-per-node=7 --gres=gpu:p100:1 --time=01:00:00 --pty --wait=0 /bin/bash
