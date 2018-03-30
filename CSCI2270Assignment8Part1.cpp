#include "Assignment8Graph.h"
#include "Assignment8Graph.cpp"

using namespace std;

int main(int argc, char * argv[]){

    //READ IN THE FILE AND CONSTRUCT THE GRAPH

    //create an instance of the graph
    Graph initGraph;

    //stores cities for putting in edges
    vector<string> listOfCities;

    //the file we're opening is the first argument passed through
    ifstream in_stream(argv[2]);

    //check to see if opening worked.
    if(in_stream.is_open()){

        string currentLine = "";
        //the first line is used to add vertices, additional lines will be used to add edges
        int lineIndex = 0;

        //get every line from the file
        while(getline(in_stream, currentLine)){

                //In each line, create a stringstream
                stringstream splitLine(currentLine);
                string currentWord = "";

                //used so we can ignore certain words from the table
                int wordIndex = 0;

                //Now, go through every word in the stringstream, delimiting by comma
                while(getline(splitLine, currentWord, ',')){


                    //The first line should just add vertices.
                    if(lineIndex == 0){

                            //skip 'dest/source'
                            if(wordIndex == 0){
                                wordIndex ++;
                            }

                            //add vertices to the graph
                            //add cities to our list for putting in edges
                            else{
                                initGraph.addVertex(currentWord);
                                listOfCities.push_back(currentWord);
                            }

                    }

                    //If the line index is greater than 0, we want to add edges
                    else{

                        //Skip the first word; we just want to get weights
                        if(wordIndex == 0){
                            wordIndex++;
                        }

                        //Now, add every edge
                        else{
                            //turn the weight to an int
                            int weight = stoi(currentWord);

                            //Only add if the weight is positive
                            //the line index will always keep track of the starter city
                            //The word index tracks what the new end city is
                            if(weight > -1){
                                initGraph.addEdge(listOfCities[lineIndex-1], listOfCities[wordIndex - 1], weight);
                            }

                            //Increment the word index when we're done checking a word/weight
                            wordIndex++;
                        }
                    }

                }

                //increment line index when we're done reading one line
                lineIndex++;
        }

    }

    else{
        cout<<"There was an error opening the file!"<<endl;
    }

    //initGraph.displayEdges();

    //controls re-printing or exiting the menu
    bool continueMenu = true;

    while(continueMenu){

        //Display a menu
        cout << "======Main Menu======" << endl;
        cout << "1. Print vertices" << endl;
        cout << "2. Vertex adjacent" << endl;
        cout << "3. Quit" << endl;

        //Get what the user wants to do
        char userChoice;
        cin>>userChoice;

        //Print a list of the vertices and their adjacent vertices
        if(userChoice == '1'){
            initGraph.displayEdges();
        }

        //the user can check if two vertices are adjacent
        else if(userChoice == '2'){

            //clear the stream
            cin.ignore();
            string firstCity;
            string secondCity;

            cout<<"Enter first city:"<<endl;
            cin>>firstCity;

            cout<<"Enter second city:"<<endl;
            cin>>secondCity;

            //Print true if they're adjacent, false if not adjacent
            if(initGraph.isAdjacent(firstCity, secondCity) == 1){
                cout<<"True"<<endl;
            }
            else{
                cout<<"False"<<endl;
            }

        }

        //Exit the menu
        else if(userChoice =='3'){
            cout<<"Goodbye!"<<endl;
            continueMenu = false;
        }

        //Choice not valid; re-display menu
        else{
            cout<<"Not a vaild choice!"<<endl;
        }
    }

    return 0;
}
