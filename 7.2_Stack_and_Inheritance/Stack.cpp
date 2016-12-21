class Stack {
    int buf[256], sp;
public:
    Stack() { sp=256; }
    void push(int i) { buf[--sp]=i; }
    int pop() { return buf[sp++]; }
    int empty() { return sp==256; } };
