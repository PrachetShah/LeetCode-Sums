class ParkingSystem {
public:
    vector<int> spaces;
    ParkingSystem(int big, int medium, int small) {
        this->spaces = {big, medium, small};
    }
    
    bool addCar(int carType) {
        if(this->spaces[carType-1] != 0){
            this->spaces[carType-1]--;
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */