enum status
{
	BEGIN, /* the file has just been initalized */
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
