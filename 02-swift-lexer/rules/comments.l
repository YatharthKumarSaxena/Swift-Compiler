"//".* {
    /* Single Line Comment */
}

"/*" {
    BEGIN(COMMENT);
}

<COMMENT>"*/" {
    BEGIN(INITIAL);
}

<COMMENT>. {
    /* Ignore comment content */
}

<COMMENT>\n {
    /* Ignore newline inside comment */
}