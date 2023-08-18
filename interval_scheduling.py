def minimal_point_set_interval_cover(intervals : list[(int,int)]) -> int :
    """
    Returns the minimal number of points needed to cover all the intervals.
    """
    intervals.sort(key=lambda x: (x[1],x[0]))
    temp_start = intervals[0][0]
    temp_end = intervals[0][1]
    count = 1
    list_of_points = []
    for(start, end) in intervals:
        if start > temp_end:
            list_of_points.append((temp_end+temp_start)/2)
            count +=1
            temp_start = start
            temp_end = end
        else:
            temp_start = start
    list_of_points.append((temp_end+temp_start)/2)
    return count, list_of_points

def main():
    intervals = [(1,3),(2,5), (3,6),(5,10),(7,8),(9,11),(12,14),(13,15)]
    print(minimal_point_set_interval_cover(intervals))
if __name__ == "__main__":
    main()