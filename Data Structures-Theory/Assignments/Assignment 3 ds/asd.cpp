#include <bits/stdc++.h>
#include <queue>

using namespace std;

 
struct Node {
    int data;
    Node* left;
    Node* right;
};
void helper(vector<int>& res, Node* root, int d)
{
    if (!root)
        return;
 
    // Expand list size
    if (d == res.size())
        res.push_back(root->data);
 
    else
 
        // to ensure largest value
        // on level is being stored
        res[d] = max(res[d], root->data);
 
    // Recursively traverse left and
    // right subtrees in order to find
    // out the largest value on each level
    helper(res, root->left, d + 1);
    helper(res, root->right, d + 1);
}
 
// function to find largest values
vector<int> largestValues(Node* root)
{
    vector<int> res;
    helper(res, root, 0);
    return res;
}
void inorder(Node* temp)
{
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}


// return height of tree
int heightoftree(Node* root)
{
 
    if (root == NULL)
        return 0;
 
    int left = heightoftree(root->left);
    int right = heightoftree(root->right);
 
    return ((left > right ? left : right) + 1);
}
Node* CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int findMax(Node* root)
{
    // Base case
    if (root == NULL)
        return INT_MIN;
 
    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->data;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}
Node* InsertNode(Node* r, int data)
{
    if (r == NULL) {
        r = CreateNode(data);
         return r;
    }
    if(r->data>data){
        r->left=InsertNode(r->left,data);
    }
    else{
       r->right= InsertNode(r->right,data);
    }
    return r;
}

int findMin(struct Node* root)
{
    // Base case
    if (root == NULL)
      return INT_MAX;
 
    // Return minimum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->data;
    int lres = findMin(root->left);
    int rres = findMin(root->right);
    if (lres < res)
      res = lres;
    if (rres < res)
      res = rres;
    return res;
}
void printPerLevelMinimum(Node* root,
                  vector<int>& res, int level)
{
     
    if (root != NULL) {
 
        printPerLevelMinimum(root->left,
                              res, level + 1);
 
        if (root->data < res[level])
            res[level] = root->data;
 
        printPerLevelMinimum(root->right,
                              res, level + 1);
    }
}
 
void perLevelMinimumUtility(Node* root,int min[])
{
     
    // height of tree for the size of
    // vector array
    int n = heightoftree(root), i;
 
    // vector for store all minimum of
    // every level
    vector<int> res(n, INT_MAX);
 
    // save every level minimum using
    // inorder traversal
    printPerLevelMinimum(root, res, 0);
 
    // print every level minimum
//    cout << "Every level minimum is\n";
    for (i = 0; i < n; i++) {
//        cout << "level " << i <<" min is = "  << res[i] << "\n";
        min[i]=res[i];                    
    }
}





int main()
{
	int i;
	cin >> i;

	int arr[i];
	
	for(int x=0;x<i;x++)
	{
		cin >> arr[x];
	}
	
	Node *root=CreateNode(arr[0]);
	
	for(int x=1;x<i;x++)
	{
		root = InsertNode(root, arr[x]);
	}
//	inorder(root);
	
	int h=heightoftree(root);
	int min[h]={0};
	int max[h]={0};
	
	perLevelMinimumUtility(root,&min[0]);	
	vector<int> res = largestValues(root);
	
	for(int x=0;x<h;x++)
	{
		cout << min[x]<< " " << res[x] << endl;
	}
	 
		
	return 0;
}
