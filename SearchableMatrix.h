#ifndef AP_SECONDMS_SEARCHABLEMATRIX_H
#define AP_SECONDMS_SEARCHABLEMATRIX_H

#include "../../Desktop/New folder/MyException.h"
#include "Searchable.h"
#include <list>

#define MINIMUM_SIZE 2
#define WALL_VAL -1
#define SIZE_ERR "Cannot create a matrix in the given size!"
#define OUT_OF_BOUNDRY "The given location is out of boundry!"


struct Cell {
    int row;
    int column;
};

/***
 * Represents a searchable matrix.
 * must be instantiated with valid size number.
 * before use be sure to set entrance and exit with Locations!
 */
class SearchableMatrix : public Searchable<Cell> {

    int **_matrix;
    int _rowLength;
    Cell _entrance;
    State<Cell> _exitStateIndicator;

    static std::list<Cell> ValidMovements;

    SearchableMatrix() = default;   // Cannot be used externally

    void AllocateMatrix();

    State<Cell> *GetStateInOffSetOf(State<Cell> *base,
                                    int xDir,
                                    int yDir);

    void LoadValidMovements();

public:
    // Ctors and Dtor
    explicit SearchableMatrix(int _rowLength);

    SearchableMatrix(const SearchableMatrix &other); // copy constructor

    SearchableMatrix(SearchableMatrix &&other) noexcept; // move constructor

    SearchableMatrix &operator=(const SearchableMatrix &other); //cpy assignment

    SearchableMatrix &operator=(SearchableMatrix &&other) noexcept; //mv assign

    virtual ~SearchableMatrix();


    // Class Specific Functions
    void SetData(std::vector<int> &data);

    void SetInitalState(Cell start);

    void SetExitState(Cell end);


    // Searchable Override Functions
    State<Cell> *GetInitialState() override;

    bool isGoal(State<Cell> &state) override;

    std::vector<State<Cell> *> GetReachable(State<Cell> &state) override;

};

#endif
