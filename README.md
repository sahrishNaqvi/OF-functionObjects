# Tortusoity

- Tortusoity is a new function object of OF
- Velocity based Tortuosity definition [How to calculate tortuosity easily](https://www.researchgate.net/publication/221941283_How_to_Calculate_Tortuosity_Easily) is implemented in OF-v10.
- To compile it you need to add Tortuosity.C and Tortuosity.H files in the functionObjectes of OF and complie functionObjects with **wmake**.
- Do not forget to create Tortuosity source code file in /opt/openfoam10/etc/caseDicts/postProcessing/fields directory. 
- To use it, you need to simply type: `<solver> -postProcess -func Tortuosity` after completion of your simulations let say on the latestTime with flag -latestTime
