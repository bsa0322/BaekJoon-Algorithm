SELECT COUNT(*) as COUNT
FROM ECOLI_DATA as e
WHERE ((e.GENOTYPE & 2) = 0) and (((e.GENOTYPE & 1) = 1) or ((e.GENOTYPE & b'100') = b'100'))
;