dat = read.csv('data.csv')

# TODO don't graph n vs. n
for (name in names(dat)) {
    name_split = strsplit(name, '\\.')[[1]]
    data_type = name_split[1]
    pivot_type = name_split[2]

    png(paste0('results/', data_type, '-', pivot_type, '.png'))
    plot(dat[['n']], dat[[name]], xlab='n', ylab='Time', main=paste0(data_type, ' data, with ', pivot_type, ' pivot'))
    dev.off()
}
