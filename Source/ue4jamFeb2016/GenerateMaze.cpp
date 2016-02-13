// Fill out your copyright notice in the Description page of Project Settings.

#include "ue4jamFeb2016.h"
#include "GenerateMaze.h"


TArray<FCell> UGenerateMaze::GenerateMaze(int32 mazeWidth, int32 mazeLength, int32 seed)
{
	// create the cell array
	srand(seed);
	TArray<FCell> cells;
	cells.SetNum(mazeWidth*mazeLength, true);
	for (int i = 0; i < cells.Num(); i++)
		cells[i].index = i;

	// Create current cells and add a random one
	TArray<FCell> curCells;
	curCells.Add(cells[7]);
	curCells.Last().visited = true;

	// Create the maze
	while (curCells.Num() > 0) {

		// Get the current cell's number
		int32 curCell = curCells.Num()-1, cell = curCells[curCell].index;

		// Get neighbors of the last cell
		TArray<FCell> neighbors;
		if (cell - mazeWidth >= 0 && (cell - mazeWidth) % mazeWidth == cell % mazeWidth && !cells[cell - mazeWidth].visited)
			neighbors.Add(cells[cell - mazeWidth]);
		if (cell + mazeWidth < cells.Num() && (cell + mazeWidth) % mazeWidth == cell % mazeWidth && !cells[cell + mazeWidth].visited)
			neighbors.Add(cells[cell + mazeWidth]);
		if (cell - 1 >= 0 && (cell - 1) / mazeWidth == cell / mazeWidth && !cells[cell - 1].visited)
			neighbors.Add(cells[cell - 1]);
		if (cell + 1 >= 0 && (cell + 1) / mazeWidth == cell / mazeWidth && !cells[cell + 1].visited)
			neighbors.Add(cells[cell + 1]);

		// Check if no neighbors and remove if so otherwise pick a random to add the the current cells
		if (neighbors.Num() == 0) {
			curCells.RemoveAt(curCell);
		}
		else {
			curCells.Add(neighbors[rand() % neighbors.Num()]);
			cells[curCells.Last().index].visited = true;
			if (cell + mazeWidth == curCells.Last().index){
				cells[cell].sides[0] = false;
				cells[curCells.Last().index].sides[1] = false;
			}
			else if (cell - mazeWidth == curCells.Last().index) {
				cells[cell].sides[1] = false;
				cells[curCells.Last().index].sides[0] = false;
			}
			else if (cell + 1 == curCells.Last().index) {
				cells[cell].sides[2] = false;
				cells[curCells.Last().index].sides[3] = false;
			}
			else if (cell - 1 == curCells.Last().index) {
				cells[cell].sides[3] = false;
				cells[curCells.Last().index].sides[2] = false;
			}
		}

	}

	//UE_LOG(LogTemp, Log, TEXT("Done!!!!"));

	return cells;
}
