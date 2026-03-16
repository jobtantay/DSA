void addRunner(Club *C, char name[], int distance, float time){
    if(C->count != MAX_RUNNERS){
        strcpy(C->runners[C->count].name, name);
        C->runners[C->count].history.runs[C->runners->history.count].distance = distance;
        C->runners[C->count].history.runs[C->runners->history.count].time = time;
        C->count++;
        C->runners[C->count-1].history.count++;
    }
}