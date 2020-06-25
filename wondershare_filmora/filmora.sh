#!/bin/bash  
  WINEPREFIX=$HOME/.filmora/ winetricks vcrun2015
  WINEPREFIX=$HOME/.filmora/ winetricks directx9
  wget https://github.com/doitsujin/dxvk/releases/download/v0.96/dxvk-0.96.tar.gz -O $HOME/.filmora/dxvk-0.96.tar.gz
  tar xvzf $HOME/.filmora/dxvk-0.96.tar.gz -C $HOME/.filmora
  cd $HOME/.filmora/dxvk-0.96
  WINEPREFIX=$HOME/.filmora/ winetricks --force $HOME/.filmora/dxvk-0.96/setup_dxvk.verb
  cd ..
  wget https://effects.wondershare.com/download/5bf4f349ad488/filmora_full846.exe -O $HOME/.filmora/filmora_full846.exe
  WINEPREFIX=$HOME/.filmora/ wineserver -w
  echo "-- Install filmora and not run filmora--" 
  WINEPREFIX=$HOME/.filmora/ wine $HOME/.filmora/filmora_full846.exe
  echo "-- run winecfg and change version to windowsxp to windows7 --"
  echo "-- add opencl.dll and msvcr120.dll to library --"
  echo "-- Enable VAAPI Staging options --" 
  echo "-- Disable allow the window manager to decorate the windows --"
  WINEPREFIX=$HOME/.filmora/ winecfg
