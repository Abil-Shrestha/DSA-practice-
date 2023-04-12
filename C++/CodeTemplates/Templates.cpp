//one input, opposite ends
int fn(vector<int>& arr) {
    int left = 0;
    int right = int(arr.size()) - 1;
    int ans = 0;

    while (left < right) {
        // do some logic here with left and right
        if (CONDITION) {
            left++;
        } else {
            right--;
        }
    }

    return ans;
}

//two inputs, opposite ends
int fn(vector<int>& arr1, vector<int>& arr2) {
    int left1 = 0;
    int right1 = int(arr1.size()) - 1;
    int left2 = 0;
    int right2 = int(arr2.size()) - 1;
    int ans = 0;

    while (left1 < right1 && left2 < right2) {
        // do some logic here with left1, right1, left2, right2
        if (CONDITION) {
            left1++;
        } else {
            right1--;
        }
    }

    return ans;
}

//sliding window
int fn(vector<int>& arr) {
    int left = 0;
    int right = 0;
    int ans = 0;

    while (right < arr.size()) {
        // do some logic here with left and right
        if (CONDITION) {
            right++;
        } else {
            left++;
        }
    }

    return ans;
}

//Build a prefix sum array
vector<int> prefixSum(vector<int>& arr) {
    vector<int> prefix(arr.size() + 1, 0);
    for (int i = 1; i <= arr.size(); i++) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    return prefix;
}

//LinkedList fast and slow pointer
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        //do some logic here with slow and fast
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//Reversing a Linked List
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

//Find number of subarrays that fit an exact criteria
int fn(vector<int>& arr) {
    int ans = 0;
    int left = 0;
    int right = 0;
    int sum = 0;

    while (right < arr.size()) {
        // do some logic here with left and right
        if (CONDITION) {
            right++;
        } else {
            left++;
        }
    }

    return ans;
}

//Monotonic increasing stack
vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> ans(nums.size(), -1);
    stack<int> st;
    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

//Binary tree: DFS (recursive)
int dfs(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int ans = 0;
    // do logic
    dfs(root.left);
    dfs(root.right);
    return ans;
}

//Binary tree: DFS (iterative)
int dfs(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int ans = 0;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        // do logic
        if (curr->right != nullptr) {
            st.push(curr->right);
        }
        if (curr->left != nullptr) {
            st.push(curr->left);
        }
    }
    return ans;
}

//  Binary tree: BFS (iterative)
int bfs(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int ans = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        // do logic
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
    }
    return ans;
}   

//Binary Tree: BFS ( recursive)
    int bfs(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int ans = 0;
    // do logic
    dfs(root.left);
    dfs(root.right);
    return ans;
}


//Caclulate Height of a tree
int height(Node* root) {
        if (root == NULL)
        return -1;
        else{
            int lh = height(root->left) + 1;
            int rh = height(root->right) + 1;
            return rh >= lh ? rh : lh;
        }
    }

//Top view of a tree
void topView(struct Node *root)
{
    if(root == NULL)
        return;
    queue<pair<Node*, int>> q;
    map<int, int> m;
    q.push(make_pair(root, 0));
    while(!q.empty())
    {
        pair<Node*, int> p = q.front();
        Node* n = p.first;
        int h = p.second;
        q.pop();
        if(m.find(h) == m.end())
            m[h] = n->data;
        if(n->left != NULL)
            q.push(make_pair(n->left, h-1));
        if(n->right != NULL)
            q.push(make_pair(n->right, h+1));
    }
    for(auto it = m.begin(); it != m.end(); it++)
        cout << it->second << " ";
}

//Level order Traversal
void levelOrder(Node * root) {
        if (root == nullptr) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* c = q.front();
            cout<<c->data<<" ";
            if(c->left != nullptr)q.push(c->left);
            if(c->right != nullptr)q.push(c->right);
            q.pop();
        }
    }
    
    //heap sort
    void heapify(int arr[], int n, int i)  
    {  
        int largest = i; // Initialize largest as root  
        int l = 2*i + 1; // left = 2*i + 1  
        int r = 2*i + 2; // right = 2*i + 2  
      
        // If left child is larger than root  
        if (l < n && arr[l] > arr[largest])  
            largest = l;  
      
        // If right child is larger than largest so far  
        if (r < n && arr[r] > arr[largest])  
            largest = r;  
      
        // If largest is not root  
        if (largest != i)  
        {  
            swap(arr[i], arr[largest]);  
      
            // Recursively heapify the affected sub-tree  
            heapify(arr, n, largest);  
        }  
    }

    // graph sort
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack)  
    {  
        // Mark the current node as visited.  
        visited[v] = true;  
      
        // Recur for all the vertices adjacent to this vertex  
        list<int>::iterator i;  
        for (i = adj[v].begin(); i != adj[v].end(); ++i)  
            if (!visited[*i])  
                topologicalSortUtil(*i, visited, Stack);  
      
        // Push current vertex to stack which stores result  
        Stack.push(v);  
    }