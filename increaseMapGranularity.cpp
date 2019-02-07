#include <vector>
#include <iostream>
using namespace std;
int main(){
    float value;
    int height = 3;
    int width = 3;
    int index = 0;
    float map[] = { 0,  0,  0,
                    0  ,100,  0,
                    100,  0,  100};
    for(int i = 0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << map[index++] << "\t";
        }
        cout << endl;
    }

    cout << endl;
    
    // increase the granularity of the map by 4 
    index = 0;
    std::vector<std::vector<float> > occupancyGrid, tmp;
    for (int i = 0; i < height; i++) {
        std::vector<float> row1,row2,row3,row4;
        for (int j = 0; j < width; j++) {
            row1.push_back(map[index]);
            row1.push_back(map[index]);
            row1.push_back(map[index]);
            row1.push_back(map[index]);

            row2.push_back(map[index]);
            row2.push_back(map[index]);
            row2.push_back(map[index]);
            row2.push_back(map[index]);

            row3.push_back(map[index]);
            row3.push_back(map[index]);
            row3.push_back(map[index]);
            row3.push_back(map[index]);

            row4.push_back(map[index]);
            row4.push_back(map[index]);
            row4.push_back(map[index]);
            row4.push_back(map[index]);
            index++;
        }
        occupancyGrid.push_back(row1);
        occupancyGrid.push_back(row2);
        occupancyGrid.push_back(row3);
        occupancyGrid.push_back(row4);
    }
    tmp = occupancyGrid;
    
    cout << "rows: " << occupancyGrid.size() << " cols: " << occupancyGrid.at(0).size() << endl;
    for(int i = 0; i<occupancyGrid.size(); i++){
        for(int j=0; j<occupancyGrid.at(0).size(); j++){
            cout << occupancyGrid.at(i).at(j) << "\t";
        }
        cout << endl;
    }

    for(int i = 0; i<occupancyGrid.size(); i++){
        for(int j=0; j<occupancyGrid.at(0).size(); j++){
            double value = occupancyGrid.at(i).at(j);
            // the row above
            if(value > 0){
                try{
                    tmp.at(i-1).at(j-1) = value;
                } catch (...){};
                try{
                    tmp.at(i-1).at(j) = value;
                } catch(...){};
                try{
                    tmp.at(i-1).at(j+1) = value;
                } catch(...){};
                
                // this row
                try{
                    tmp.at(i).at(j-1) = value;
                } catch(...){};
                try{
                    tmp.at(i).at(j) = value;
                } catch(...){};
                try{
                    tmp.at(i).at(j+1) = value;
                } catch(...){};
                
                // row below
                try{
                    tmp.at(i+1).at(j-1) = value;
                } catch(...){};
                try{
                    tmp.at(i+1).at(j) = value;
                } catch(...){};
                try{
                    tmp.at(i+1).at(j+1) = value;
                } catch(...){};
            }
        }
    }
    
    occupancyGrid = tmp;

    cout << "rows: " << occupancyGrid.size() << " cols: " << occupancyGrid.at(0).size() << endl;
    for(int i = 0; i<occupancyGrid.size(); i++){
        for(int j=0; j<occupancyGrid.at(0).size(); j++){
            cout << occupancyGrid.at(i).at(j) << "\t";
        }
        cout << endl;
    }
    return 0;
}