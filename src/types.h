enum status
{
	WAITING, /* the file has just been initalized, and when it is waiting to start */
	RUNNING, /* the file is downloading */
	FINISHED, /* the file has finished downloading */
	CANCELED, /* the file has been cancelled by the user */
	INTERUPTED /* a network/program error occured */
};

typedef struct downloaditem
{
	char *url; /* where the file is being downloaded from - self explainitory */
	unsigned priority; /* where the file is on the queue */
	float progress; /* percentage of the file downloaded */
	enum status state; /* state which the file is in, typically running or finished */
	struct downloaditem *next; /* next item on the queue */
} dl_t;

typedef struct hashtable
{
	char **keys; /* the string which maps to the index */
	int index; /* the array's index */
	void *array; /* a pointer to the array */
	
} hash_t;
