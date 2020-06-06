# Unofficial repository EndeavourOS

This repository for **EndeavourOS** contains packages compiled specifically for it. How to proceed with the installation:

Add pacman key
> sudo pacman-key --recv-keys AEE1E900

Let's add the repository in pacman:

> sudo nano /etc/pacman.conf

add code:

```
[codelinsoft-eos-repository] 
SigLevel = PackageRequired
Server = https://repository.codelinsoft.it/eos-repository
```
Install keyring
> sudo pacman -Syu codelinsoft-keyring

If the keyring installation fails, proceed as follows:

change code:

```
[codelinsoft-eos-repository] 
SigLevel = Never
Server = https://repository.codelinsoft.it/eos-repository
```
Install keyring
> sudo pacman -Syu codelinsoft-keyring

We install the EndeavorOS Settings Manager

>sudo pacman -S eos-settings-manager

# Screenshot:

# EOS settings managaer
![eos_settings_manager](/screenshot_theme/eos_settings_manager_new.png)
## EOS Kernel manager installer
![eos_settings_manager1](/screenshot_theme/eos_settings_manager_kernel.png)
## EOS kcm module plasma
![eos_settings_manager](/screenshot_theme/eos_settings_manager_plasma.png)

# Deepin 
![deepin_theme](/screenshot_theme/deepin_theme.png)

# Cinnamon 
![cinnamon_theme](/screenshot_theme/cinnamon_theme.png)

# Gnome 
![gnome_theme](/screenshot_theme/gnome_theme.png)

# Mate
![mate_theme](/screenshot_theme/mate_theme.png)

# Kde
![kde_theme](/screenshot_theme/kde_theme.png)

# Credit
EOS settings managaer ( fork Manjaro settings managaer )
Calogero Scarnà - manteiner repository
