## Installing Soft-RoCE on Ubuntu 24.04

`apt install rdma-core` - i guess RDMA core includes softROCE now.

 RxE config was removed in v28. So need to make sure you install the old v27.

 
To configure soft-roce, follow:
1. https://enterprise-support.nvidia.com/s/article/howto-configure-soft-roce
2. https://manpages.ubuntu.com/manpages/focal/en/man8/rxe_cfg.8.html
