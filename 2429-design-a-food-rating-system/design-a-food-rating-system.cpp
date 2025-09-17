class FoodRatings {
public:
    
    unordered_map<string, set<pair<int, string>> >mp; // cuisine - food map
    // The set will automatically Store food according to the increasing rating, 
    // and if there is a tie between ratings, it will automatically sort according to 
    // lexicographic, order of food.
    unordered_map<string, int> mp2; // food - rating map

    // food -> cuisine
    unordered_map<string,string>mp3;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();

        for (int i = 0; i < n; i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            mp[cuisine].insert({-rating, food}); // corner case
            mp2[food] = rating;
            mp3[food] = cuisine;
        }
    }

    void changeRating(string food, int newRating) { 
        string cuisine = mp3[food];
        int oldRating = mp2[food];

        mp2[food]=newRating;

        mp[cuisine].erase({-oldRating, food});
        mp[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine) {
        string food = mp[cuisine].begin()->second;
        return food;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */