class FoodRatings {
public:
    struct cmp{
        bool operator()(const pair<int,string> &lhs, const pair<int,string> &rhs) const 
        {
            if(lhs.first!=rhs.first){
                return lhs.first>rhs.first;
            }
            else
                return lhs.second<rhs.second;
        }
    };
    
    map<string,int> rating;
    map<string,set<pair<int,string>,cmp>> food_map;
    map<string,string> cuisines_map;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            rating[foods[i]]=ratings[i];
            food_map[cuisines[i]].insert({ratings[i],foods[i]});
            cuisines_map[foods[i]]=cuisines[i];
            // if (indexes.find(cuisines[i]) == indexes.end()) {
            //     indexes[cuisines[i]]=curr;
            //     curr++;
            // }
            // food_map[indexes[cuisines[i]]].insert(make_pair(ratings[i],foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        food_map[cuisines_map[food]].erase({rating[food],food});
        food_map[cuisines_map[food]].insert({newRating,food});
        rating[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return (food_map[cuisine].begin())->second;
        //set<pair<int,string>> x = food_map[indexes[cuisine]];
        //return x.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */