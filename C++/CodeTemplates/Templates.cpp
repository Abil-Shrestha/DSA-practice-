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