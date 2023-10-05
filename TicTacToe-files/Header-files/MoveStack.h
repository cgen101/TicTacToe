//The move stack specification file.  It stores the history of the moves
// currently in effect

// Represents a players move by storing the
// x,y coordinates
// Added constructor functions to this struct to simplify the code
struct Move{
    int x;
    int y;
    Move(){ x=0; y=0; }
    Move(int a, int b) { x=a, y=b;}
};

class MoveStack{
private:
    static const int stackSize=9;
    int head=-1;
    Move gameStack[stackSize]; 

public:
    int currStackSize=0; 
    MoveStack();
    ~MoveStack();
    int getSize();
    Move top();
    void push(Move move);
    void pop();
    bool isFull() const;
    bool isEmpty() const;
};




