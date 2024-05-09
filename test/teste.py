def sequence_time(*args):
    total_minutes = sum(args)
    if total_minutes < 60:
        return f"Total time to launch is {total_minutes} minutes"
    else:
        return f"Total time to launch is {round(total_minutes/60)} hours and {total_minutes%60} minutes"
    
print(sequence_time(10, 20, 3987))