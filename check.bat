@echo off
for %%F in (*.c) do (
    if /I not "%%~nxF" == "libft_test.c" (
        norminette "%%F"
    )
)
