element(air).
element(earth).
element(fire).
element(water).

compound(animal,[life,forest]).
compound(bird,[animal,air]).
compound(cloud, [water,air]).
compound(fish,[life,ocean]).
compound(forest, [plant,plant]).
compound(life, [lightning,ocean,volcano]).
compound(lightning, [storm,cloud,earth]).
compound(ocean, [water,water,water]).
compound(plant, [earth,life]).
compound(rain, [cloud,water]).
compound(storm, [cloud,wind]).
compound(volcano, [fire,earth]).
compound(wind, [air,air]).
