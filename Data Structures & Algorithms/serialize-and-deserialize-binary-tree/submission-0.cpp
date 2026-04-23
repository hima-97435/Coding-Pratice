/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerial(root,res);
        return join(res,",");

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = spilt(data,',');
        int i=0;
        return dfsDeserial(vals,i);
    }
    private:
     void dfsSerial(TreeNode* node, vector<string> & res){
        if(!node) {
            res.push_back("N");
            return;

        }
        res.push_back(to_string(node->val));
        dfsSerial(node->left,res);
        dfsSerial(node->right, res);

     }
     TreeNode* dfsDeserial(vector<string> & vals , int &i){
        if(vals[i] == "N") {
            i++;
            return NULL;

        }
        TreeNode* n = new TreeNode(stoi(vals[i]));
        i++;
        n->left=dfsDeserial(vals,i);
        n->right=dfsDeserial(vals,i);
        return n ;
     }
     vector<string> spilt(const string&s , char delim){
        vector<string> ele;
        stringstream ss(s);
        string item ;
        while(getline(ss, item , delim)){
            ele.push_back(item);
        }
        return ele;
     }
     string join(const vector<string> &v , const string &delim){
        ostringstream s;
        for(const auto &i : v) {
            if(&i != &v[0]) s<<delim;
            s<<i;
        }
        return s.str();
     }

};
