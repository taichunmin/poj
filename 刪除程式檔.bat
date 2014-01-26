@echo off
echo 將會刪除的檔案如下: (不會移除唯獨的檔案)
dir /b /s /a-r *.exe *.class *.o | more
pause
echo 即將刪除檔案
timeout 3
del /s /q /a-r *.exe *.class *.o
