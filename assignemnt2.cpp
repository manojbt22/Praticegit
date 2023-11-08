#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head, int data)
{
    struct node *temp = *head;
    if (*head == NULL)
    {
        temp = new node;
        *head = temp;
        temp->data = data;
        temp->next = NULL;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new node;
    temp->next->data = data;
    temp->next->next = NULL;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(vector<int> &arr, int i, int n)
{
    if (i < 0)
        return;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int pos = i;
    if (left >= n)
        arr[left] = INT_MAX;
    else if (right >= n)
        arr[right] = INT_MAX;

    if (arr[right] < arr[left] && arr[i] > arr[right])
    {
        pos = right;
    }

    if (arr[left] < arr[right] && arr[i] > arr[left])
    {
        pos = left;
    }

    if (pos != i)
    {
        swap(&arr[i], &arr[pos]);
        heapify(arr, (i - 1) / 2, n);
    }
}
int main()
{
    int k;
    cout << "Enter the no. of linked list = ";
    cin >> k;
    int c;
    cout << "Enter the no of elements in the linked list  = ";
    cin >> c;

    struct node *head[k];
    vector<int> arr;
    for (int i = 0; i < k; i++)
    {
        cout << "Enter the elements of the linked list " << i + 1 << " = ";
        for (int j = 0; j < c; j++)
        {
            int data;
            cin >> data;
            insert(&head[i], data);
            arr.push_back(data);
        }
    }

    for (int i = 0; i < k / 2; i++)
    {
        heapify(arr, i, k);
    }

    cout << ("resultant array = ") << endl;
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "heap sort = " << endl;
    int n = k;
    int result_arr[k];
    struct node *result = NULL;

    for (int i = 0; i < k; i++)
    {
        result_arr[i] = arr[0];
        insert(&result, arr[0]);
        swap(&arr[0], &arr[arr.size() - 1]);
        arr.pop_back();

        for (int j = 0; j < arr.size() / 2; j++)
            heapify(arr, j, arr.size());
    }

    for (int i = 0; i < 12; i++)
        cout << result_arr[i] << " ";

    struct node *temp = result;
    while (temp != NULL)
    {
        cout << temp->data << " ";
    }
}