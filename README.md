# Tortusoity

## Tortuosity Function Object in OpenFOAM
- Tortusoity is a new function object of OF
- Tortuosity is introduced as a new function object in OpenFOAM (OF).

## Compilation Instructions:

The implementation is based on the definition provided in [How to calculate tortuosity easily](https://www.researchgate.net/publication/221941283_How_to_Calculate_Tortuosity_Easily) and is available in OF version 10.
  *Source Files*: Place the **Tortuosity.C** and **Tortuosity.H** files into the **functionObjects** directory of OpenFOAM.

*Compilation*: Navigate to the **functionObjects** directory and execute wmake to compile the necessary files.

*Source Code File Creation*: Ensure you create the Tortuosity source code file. It should be located at **/opt/openfoam10/etc/caseDicts/postProcessing/fields**.

*Updating the Make Directory*: Add a reference to Tortuosity/Tortuosity.C within the files located inside the Make directory.

## Usage
- After completing your simulations, the Tortuosity function object can be invoked using the command: `<solver> -postProcess -func Tortuosity -latestTime`.
- Replace <solver> with the appropriate solver you're using. The -latestTime flag indicates that the function should operate on the most recent simulation time.
