class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> arr;
        
        for (auto &op : operations) {
            if (op == "C") {
                // remove last score
                arr.pop_back();
            } 
            else if (op == "D") {
                // double last score
                arr.push_back(arr.back() * 2);
            } 
            else if (op == "+") {
                // sum of last two scores
                int v1 = arr[arr.size() - 1];
                int v2 = arr[arr.size() - 2];
                arr.push_back(v1 + v2);
            } 
            else {
                // numeric value
                arr.push_back(stoi(op));
            }
        }

        // total sum
        int total = 0;
        for (int x : arr) total += x;
        return total;
    }
};
