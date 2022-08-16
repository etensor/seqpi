# seqpi

Al principio solo era un visualizador de una cadena de números aleatorios.
Luego lo adapté para ver las cifras de pi, y para darle mas control le di argumentos,
luego colores y luego dos números más, phi y e. 

> pi_random_v0.cpp  -> visual_pi -> visual_pi_argv -> vispi-argv-color -> dcyphr-nums.cpp

Leería cualquier número, y el sistema no tiene que ser decimal, aunque para eso tocaría deconstruirlo acordemente.

The usage is easy:
>   cpiseq and picpp
expects 4 arguments: lim_min, lim_max, digits on screen, sleep in milliseconds interval; 
so u have time to read its output. 

>   ephiphi
expects 5: in addition to the previous 4, it expects as first argument which number you want to read. 
#### Example latest (dcypher_nums):
```zsh
    ./epiphi phi 10 100 25 60
    ./cypherviz phi 10 100 25 60

    # This will print and count from the 10th digit to the 100th digit of phi,
    # displaying 25 in screen each 60 milliseconds
```

### Or just compile it

```bash
g++ -std=c++20 dcypher-nums.cpp -o "cypherviz"
    
./cypherviz 
```
:)
