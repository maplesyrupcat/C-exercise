//ÅÐ¶ÏÀ¨ºÅÓÐÐ§ÐÔ
#define STACK_INIT_SIZE 10
#define STACK_ADD 5
typedef char Elemtype;
typedef struct Stack
{
	Elemtype *base;
	int top;
	int listsize;
}Stack;
void Stack_Init(Stack* ps)
{
	ps->base = (Elemtype*)malloc(sizeof(Elemtype)*STACK_INIT_SIZE);
	if (!ps->base) exit(-1);
	ps->top = 0;
	ps->listsize = STACK_INIT_SIZE;
}

void Stack_Destory(Stack* ps)
{
	assert(ps);
	free(ps->base);
	ps->base = NULL;
	ps->top = ps->listsize = 0;
}
void StackPush(Stack* ps, Elemtype e)
{
	assert(ps);
	if (ps->top >= ps->listsize)
	{
		Elemtype* newbase = (Elemtype*)realloc(ps->base,
			(ps->listsize + STACK_ADD)*sizeof(Elemtype));
		if (!newbase)exit(-1);
		ps->base = newbase;
		ps->listsize += STACK_ADD;
	}
	ps->base[ps->top] = e;
	ps->top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->top <= 0) return;
	ps->top--;
}
Elemtype StackTop(Stack* ps)
{
	assert(ps && ps->top>0);
	return ps->base[ps->top - 1];
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
bool isValid(char * s){
	Stack st = { 0 };
	Stack_Init(&st);
	while (*s != '\0')
	{
		if (StackEmpty(&st) && (*s == ')'
			|| *s == ']' || *s == '}')) return false;
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st, *s);
		}
		else
		{
			char tmp = StackTop(&st);
			if ((tmp == '(' &&  *s == ')') ||
				(tmp == '[' && *s == ']') ||
				(tmp == '{' && *s == '}'))
			{
				StackPop(&st);
			}
			else return false;
		}
		s++;
	}
	if (!StackEmpty(&st)) return false;
	else return true;
}