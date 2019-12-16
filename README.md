# superchess

First, build a single page code for a very simple board game that runs with main.

Then break that apart into header and source files.

//This should be... What is it called? Template. Parent class. Whatever, need to relearn terminology. What attributes will a piece have?
//Let's start by building regular chess and go from there.
//
//Name
//
//int Color
//I might change these to make some intuitive mathematical relation to the board. Up to three axes. 2, 3, 5
//1 axis: traditional chess: white is 2, black is -2
//2 axes: four player chess: red is 3, blue is -3
//3 axes: hexigonal spaces with six players: yellow is 5, green is -5
//
//Movement Rules
//
//int Value
//would also depend on rule set
//
//Does this character move independantly
//Core concept: In chess, the king is the only piece that moves. It can use its turn to move itself or another piece. In super chess, this can be expanded to other pieces such as the magistrate, chancellor, and Lord, each of which get their own turn. The Lord can move other pieces, the magistrate can perform certain other functions (such as cards, if available) the chancellor can only move itself. So it's defined by an int
//0 is normal piece
//2 is moves itself
//3 is plays cards
//5 is moves other pieces
//chancellor is 2
//magistrate is 6
//lord is 10
//king is 30
//Get it?!
//
//Pieces
//
//pawn --> chess piece
//rook --> chess piece
//bishop --> chess piece
//knight --> chess piece
//queen --> chess piece
//king --> chess piece
//checker
//checker king
//obelisk
//hunter killer
//doom queen
//suicide king
//monk
//hypnotist
//builder
//miner
//archer
//lancer
//fencer
//wall
//Indomitable Snowman
//RHU
//Juggernaught
//wizard
//slime
//
//The pieces will need components that allow for varialbe rules. Perhaps each piece is abstract, and is implemented by the specific rule set... That sounds wrong. Could the rule set be an interface for the pieces? I think that might be appropriate, bc the variable rules could apply to all, some, or one piece, or even to the board or the gameplay itself. But... for a given variable, if you don't know what state the variable is in, the piece will be unusable, so the piece will have to be abstract until it is given the correct rule set.
