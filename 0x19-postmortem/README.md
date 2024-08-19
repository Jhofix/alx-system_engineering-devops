
![Technical Issue Resolution](./http_error_500.png)

# Incident Summary
At exactly 15:45 GMT+1, we received the first report from a user @alxafrica that the web server kept returning error: 500 upon requesting for a web page.

This report could only be traced back to the most recent update on some of the php backend scripts pushed to the server at exactly 14:00 GMT+1.

After 15 minutes of the report, we were able to detect that the ‘wp-settings.php’ script in the /var/www/html/ directory contains a bug in that some parts of the script uses phpp in place of php which led to broken link upon every request for web pages.

Thanks to the backend developers who were able to detect the error in good time through the help of the log file and by running ‘strace’ on the system to be able to identify the exact point at which the error was recurring.

Based on statics, we estimated that about 30% of our users were affected within the time at which the update was made to the server and the time the issue was resolved because it happened to be during working our when an average of 60% of our users are requesting for one webpage or the other.

Fortunately, there were no further impact recorded aside the fact that users were unable to access their requested webpages and forms.
Leadup

Aside the faulty script ‘wp-settings.php’ which was the major cause of the error, there were no prior updates that contributed to this error.

# Fault
Everything was working perfectly before the most recent update prior to the error report but there was need to make change to the ‘wp-settings.php’ script to improve user experience on our website.

But contrary to what was expected, the server was unable to find the needed scripts required to load the webpages to our users because the script uses phpp in place of php throughout the entire script which led to broken links and caused the server to return error 500.

# Impact
Due to the lack of active monitoring system or any live support system, we were unable to notice the error very early until receive the first email from @alxafrica reporting the error which was 1 hour 45 minutes after the update has been pushed to the server. This caused 30% of our users to experience the error.

Within the period of the first error report email, we also got 2 other emails report the same error which indicated that many of our users have waited for so long and hoping it would be fixed sooner than it took.

# Detection
We were only able to detect the error through the error report email sent by alxafrica since that is the only option available for our website for now.

Upon receiving this email, our on-call staffs were able to respond to it and they reported the error to the backend developers immediately.

# Response
Upon receiving the report, two of our backend developers who were physically available in office were able to work together with one other developer remotely to resolve the error.

# Recovery
The first action taken by our backend team was to check through the log file thoroughly.

Following the information gathered from the log file, we ran strace on the system to monitor the process.

It took us 6 minutes to finally find out the error. We would have been able to beat the time to half assuming we have an active monitoring system to give us an hint on the specifics of the error.

# Timeline (GMT+1)
14:00 – Update pushed to server

15:45 – Error email received from alxafrica

15:47 – On-call staff responded to email

15:47 – On-call staff reported error to backend team

15:48 – Backend team started debugging process

15:54 – Backend team detected bug and fixed it

15:59 – Update was reuploaded to the server

# Root cause
The error was due to the use of phpss in place of php in the settings script which  led to broken links every time a webpage was requested.

# The five whys
There was a dare need to make some settings related changes to improve user experience.

The update was necessary due to some changes to the server system by our server host which was beyond our control.

We updated the changes locally and pushed directly to the server.

We don’t have permission to virtualize our host system for testing updates.

We could not establish enough test locally because we were not served with the test version of our host operating system.

# Backlog check
Getting a test version of the server operating system from the host or gaining necessary permissions to virtualize the system for test purposes would have very helpful in preventing this error including other errors like this but none of this options is currently available for now.

# Recurrence
This is the first occurrence of this error.

# Lessons learned
If we are not provided with the necessary permissions by our server host in the long run, then we may need to develop a test suite for this purpose on our own to help us sustain our projects on this server.
