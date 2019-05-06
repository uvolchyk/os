for i in {у е ы а о э я и ю}; do
    if [ "$i" = "$1" ]; then
        echo Гласная
        exit 0
    fi
    done
echo Согласная