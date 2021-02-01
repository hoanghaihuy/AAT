## Project description/requirements
The year is 2525, and you have been appointed to supervise a team of chrononauts adventuring through
time to collect information on the provenance and usage of various artefacts. The general overview is
described below, but most of the details are up to you.

Your code should compile on Banshee according to instructions you provide in a Readme.txt file.

Once your program is compiled into the executable AAT, it must run as follows:
./AAT n m

where n is the number of artefacts to be traced, and m is the number of jumps to be made for each
artefact. The value of n should be in the range 1 to 5 inclusive. The value of m should be in the range 1
to 10 inclusive.

Your adventure takes place across the lifetime of a population centre, which in 2525 is a metropolis
but at some distant historical point was a cluster of huts in a forest clearing near a source of clean water.

You have an initial clue as to a period in the past when information on the artefact will be available.
Each jump will take you to slightly before that date. You need to decide how to appropriately reduce the
population centre in accordance with the size and technological era.

After each jump you step the population centre foward in time, year by year, using the overloaded ++
operator, until you find the information and an additional clue. It should typically take 5-10 years to find
both of those. If no more jumps are allowed only the information needs to be gathered.

You should be reporting on all of the details of the population centre when you make a jump, so before
and after. In the year by year stepping forward you can report on the technological and population levels
each year, and otherwise just on events and the impact they have.

Report on the state of the chrononauts at the start and end of each jump period.

## Project execution
make
./AAT 5 10