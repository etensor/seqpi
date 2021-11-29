# seqpi
Al principio solo era un visualizador de una cadena de números aleatorios.
Luego lo adapté para ver las cifras de pi, y para darle mas control le di argumentos,
luego colores y luego dos números más, phi y e. 

> pi_random_v0.cpp  -> visual_pi -> visual_pi_argv -> vispi-argv-color -> dcyphr-nums.cpp

Leería cualquier número, y el sistema no tiene que ser decimal, aunque para eso tocaría darle unos retoques.

The usage is easy:
>   cpiseq and picpp
expects 4 arguments: lim_min, lim_max, digits on screen, sleep in milliseconds interval; 
so u have time to read its output. 

>   ephiphi
expects 5: in addition to the previous 4, it expects as first argument which number you want to read. 
## Example:
```zsh
    ./epiphi phi 10 100 25 60

    # This will print and count from the 10th digit to the 100th digit of phi,
    # displaying 25 in screen each 60 milliseconds
```

### Or just compile it

```bash
g++ dcypher-nums.cpp -o "epiphx"
    
./epiphx 
```
:)
