# seqpi
I made these files, made copies and evolved them, because each iteration gets better.

> pi_random_v0.cpp  -> visual_pi -> visual_pi_argv -> vispi-argv-color -> dcyphr-nums.cpp

I wrote these at first so one could in another form interact with the digits from pi
after that I wanted to add some colors to give it another level
and after that I, well if pi works why not phi and e? for now...

The executables are in main repo, gotutui, so they get called from go files

The usage is easy:
>   cpiseq and picpp
expects 4 arguments: from which digit, until, digits on screen, sleep in milliseconds interval, 
so u have time to read the output it refreshes. 

>   ephiphi
expects 5: in addition to the other 4, it expects at first which numbers 
## Example:
```zsh
    ./epiphi phi 10 100 25 60

    # This will print and count from the 10th digit to the 100th digit of phi,
    # displaying 25 in screen each 60 milliseconds
```

### To use compile executable
```c
    g++ namefile.cpp -o "name"
./name 
```

The intention with these really is to engange with go TUI components and display nicely elegant output.

