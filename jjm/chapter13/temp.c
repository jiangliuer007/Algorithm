
int RB_INSERT_FIXUP(T, z) {
    while color[p[z]] = RED
        do if p[z] = left[p[p[z]]]
            then y <- right[p[p[z]]]
                if color[y] = RED
                    then color[p[z]] <- BLACK
                         color[y]   <- BLACK
                         color[p[p[z]]] <- RED
                         z <- p[p[z]]
                    else if z = right[p[z]] 
                        then z <- p[z]

}
