options(scipen=-3)

average = function(n) {
    # Levitin, p. 180
    return (2 * n * log(n));
}

worst = function(n) {
    # Levitin, p. 180
    return ((n + 1) * (n + 2) / 2 - 3);
}

xlab = 'Array length'
ylab = 'Key comparisons'

dat = read.csv('results/data.csv')

# Average-case reference plot
png('results/reference-average.png')
plot(dat[['n']], average(dat[['n']]), type='l', xlab=xlab, ylab=ylab, main='Average-case: 2n*ln(n)')
dev.off()

# Worst-case reference plot
png('results/reference-worst.png')
plot(dat[['n']], worst(dat[['n']]), type='l', xlab=xlab, ylab=ylab, main='Worst-case: (n+1)(n+2)/2 - 3')
dev.off()

# Experimental plots
for (name in names(dat)[2:length(names(dat))]) {
    name_split = strsplit(name, '\\.')[[1]]
    data_type = name_split[1]
    pivot_type = name_split[2]

    png(paste0('results/', data_type, '-', pivot_type, '.png'))
    plot(dat[['n']], dat[[name]], xlab=xlab, ylab=ylab, main=paste0(data_type, ' data, with ', pivot_type, ' pivot'))
    dev.off()
}
