#!/bin/bash

# TEST="echo hello"
# EXPECTED=$(echo hello | bash)
# RESULT=$(echo hello | ./minishell)
# LOG="test.log"

# if [ "$EXPECTED" = "$RESULT" ]; then
#     echo "[OK] $TEST" >> "$LOG"
# else
#     echo "[KO] $TEST" >> "$LOG"
#     echo "Expected: $EXPECTED" >> "$LOG"
#     echo "Got:      $RESULT" >> "$LOG"
# fi


LOG="test.log"
> "$LOG"  # ログ初期化

COMMANDS=("echo hello" "pwd" "ls -l" "ls | grep *c" "fsda" "echo hello > tmp.txt"
"cat < tmp.txt" "ls nonexistfile 2> err.txt"
"echo hi && echo bye" "false || echo recovered" 
"cat << EOF
hello
world
EOF" )

for TEST in "${COMMANDS[@]}"; do
    EXPECTED=$(bash <<< "$TEST" 2>&1)
    RESULT=$(./minishell <<< "$TEST" 2>&1)

    bash <<< "$TEST" >/dev/null 2>&1
    STATUS_EXPECTED=$?
    ./minishell <<< "$TEST" >/dev/null 2>&1
    STATUS_RESULT=$?

    if [ "$EXPECTED" = "$RESULT" ] && [ "$STATUS_EXPECTED" -eq "$STATUS_RESULT" ]; then
        echo "[OK] $TEST (exit:$STATUS_RESULT)" >> "$LOG"
    else
        echo "[KO] $TEST" >> "$LOG"
        echo "Expected output: $EXPECTED" >> "$LOG"
        echo "Got output:      $RESULT" >> "$LOG"
        echo "Expected exit: $STATUS_EXPECTED" >> "$LOG"
        echo "Got exit:      $STATUS_RESULT" >> "$LOG"
        echo "-------------------------" >> "$LOG"
    fi
done
