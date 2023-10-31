/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2014-2016 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "Tortuosity.H"
#include "fvcGrad.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace functionObjects
{
    defineTypeNameAndDebug(Tortuosity, 0);

    addToRunTimeSelectionTable
    (
        functionObject,
        Tortuosity,
        dictionary
    );
}
}


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

bool Foam::functionObjects::Tortuosity::calc()
{
    if (foundObject<volVectorField>(fieldName_))
    {
        scalarField uMag = mag(lookupObject<volVectorField>(fieldName_));
        scalar uMag_sum = sum(uMag);
        scalarField ux = lookupObject<volVectorField>(fieldName_).component(vector::X);
        scalar ux_sum = sum(ux);
        Info<<"Tortousity" << uMag_sum/ux_sum << endl;
        return uMag_sum/ux_sum;
        //fieldName_.x()
        //return store
        //(
         //   resultName_,
         //   gSum(mag(lookupObject<volVectorField>(fieldName_)))
            //sqrt(2.0)*mag(symm(fvc::grad(lookupObject<volVectorField>(fieldName_))))
        //);
    }
    else
    {
        return false;
    }

    return true;
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::functionObjects::Tortuosity::Tortuosity
(
    const word& name,
    const Time& runTime,
    const dictionary& dict
)
:
    fieldExpression(name, runTime, dict, typeName, "U")
{
   // setResultName("U");
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::functionObjects::Tortuosity::~Tortuosity()
{}


// ************************************************************************* //
