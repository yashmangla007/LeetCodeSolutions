class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int shr = ((startTime[0]-48)*10) + (startTime[1]-48);
        int smin = ((startTime[3]-48)*10) + (startTime[4]-48);
        int ssec = ((startTime[6]-48)*10) + (startTime[7]-48);

        int ehr = ((endTime[0]-48)*10) + (endTime[1]-48);
        int emin = ((endTime[3]-48)*10) + (endTime[4]-48);
        int esec = ((endTime[6]-48)*10) + (endTime[7]-48);

        return ((ehr-shr)*3600) + ((emin-smin)*60) + (esec-ssec);
        
    }
};