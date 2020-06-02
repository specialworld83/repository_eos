# Unofficial respository EndeavorOS

This repository for **EndeavourOS** contains packages compiled specifically for it. How to proceed with the installation:

Add pacman key
> sudo pacman-key --recv-keys AEE1E900

Install keyring
> sudo pacman -S codelinsoft-keyring

Let's add the repository in pacman:

> sudo nano /etc/pacman.conf

add code:

> [eos-repository]
> SigLevel = PackageRequired
> Server = https://repository.codelinsoft.it/eos-repository

We install the EndeavorOS Settings Manager

>sudo pacman -S eos-settings-manager
