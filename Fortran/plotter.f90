SUBROUTINE TEMP(X, Y, N, T)
  REAL, INTENT(IN)    :: X, Y    ! INPUT COORDINATES
  INTEGER, INTENT(IN) :: N       ! NUMBER OF TERMS
  REAL, INTENT(OUT)   :: T       ! TEMPERATURE AT (X, Y)
  INTEGER             :: I, M
  REAL                :: K, C
  REAL                :: PI = 4.D0*DATAN(1.D0)

  !! EVALUATE SUMMATION AT (X, Y)
  T = 0
  DO I = 1, N
     K = I*PI
     C = -2*(COS(K) - 1)/(K*PI)
     T = T + C*EXP(-K*Y)*SIN(K*X)
  END DO
END SUBROUTINE TEMP


PROGRAM MAIN
  IMPLICIT NONE
  CHARACTER(len=*), PARAMETER :: F = 'POINTS.TXT'
  INTEGER,          PARAMETER :: U = 20, N = 1     ! NUMBER OF TERMS
  REAL,   DIMENSION(100, 100) :: TEMPMAP           ! ARRAY OF VOLTAGES IN VIEW
  INTEGER                     :: XN, YN
  REAL                        :: T

  DO YN = 1, 100
     DO XN = 1, 100
        CALL TEMP((XN-1)/99., (YN-1)/99., N, T)
        TEMPMAP(XN, YN) = T
     END DO
  END DO

  OPEN(UNIT=U, ACTION='WRITE', FILE=F,STATUS='REPLACE')
    DO YN = 1, 100
     DO XN = 1, 100
        WRITE(U, *) (XN-1)/99., (YN-1)/99., TEMPMAP(XN, YN)
     END DO
    END DO
  CLOSE(U)

  CALL SYSTEM('gnuplot -e "n=1" -p plot.plt')
END PROGRAM MAIN
