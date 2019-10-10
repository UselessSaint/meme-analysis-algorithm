python clear_files.py
ghc --make -O3 main.hs
for /l %%i in (1000,100,2000) do for /l %%j in (1,1,50) do main.exe %%i