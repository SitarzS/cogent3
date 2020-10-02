#!/usr/bin/env python
"""Tests for cogent3.util.unit_test, extension of the built-in PyUnit framework.
"""
from sys import exc_info

import numpy

from numpy import array, inf, log, zeros

# SUPPORT2425
# from __future__ import with_statement
from cogent3.util.unit_test import FakeRandom, TestCase, main


__author__ = "Rob Knight"
__copyright__ = "Copyright 2007-2020, The Cogent Project"
__credits__ = ["Rob Knight", "Sandra Smit", "Gavin Huttley", "Daniel McDonald"]
__license__ = "BSD-3"
__version__ = "2020.7.2a"
__maintainer__ = "Gavin Huttley"
__email__ = "Gavin.Huttley@anu.edu.au"
__status__ = "Production"


class FakeRandomTests(TestCase):
    """Tests FakeRandom class."""

    def test_call_constant(self):
        """FakeRandom __call__ should return next item from list if constant"""
        const = FakeRandom([1])
        self.assertEqual(const(), 1)
        self.assertRaises(IndexError, const)

    def test_call_constant_wrap(self):
        """FakeRandom __call__ should wrap for one-item list if specified"""
        const = FakeRandom([1], True)
        for i in range(10):
            self.assertEqual(const(), True)

    def test_call_var(self):
        """FakeRandom __call__ should work with a multi-item list"""
        f = FakeRandom([1, 2, 3])
        self.assertEqual(f(), 1)
        self.assertEqual(f(), 2)
        self.assertEqual(f(), 3)
        self.assertRaises(IndexError, f)

    def test_call_var_wrap(self):
        """FakeRandom __call__ should work with a multi-item wrapped list"""
        f = FakeRandom([1, 2, 3], True)
        result = [f() for i in range(10)]
        self.assertEqual(result, [1, 2, 3, 1, 2, 3, 1, 2, 3, 1])

    def test_cal_var_args(self):
        """FakeRandom __call__ should ignore extra args"""
        f = FakeRandom([[1, 2, 3]], True)
        for i in range(5):
            result = f((5, 5))  # shape parameter ignored
            self.assertEqual(result, [1, 2, 3])


class TestCaseTests(TestCase):
    """Tests for extension of the built-in unittest framework.

    For each test, includes an example of success and failure.
    """

    unequal_pairs = [
        (1, 0),
        ([], ()),
        (None, 0),
        ("", " "),
        (1, "1"),
        (0, "0"),
        ("", None),
        (array([1, 2, 3]), array([1, 2, 4])),
        (array([[1, 2], [3, 4]]), array([[1.0, 2.0], [3.0, 4.1]])),
        (array([1]), array([1, 2])),
        (zeros(0), array([1])),
        (array([1, 1, 1]), array([1])),
        (array([[1, 1], [1, 1]]), array([1, 1, 1, 1])),
        (zeros(0), None),
        (zeros(3), zeros(5)),
        (zeros(0), ""),
    ]

    equal_pairs = [
        (1, 1),
        (0, 0),
        (5, 5),
        (5, 5.0),
        (0, 0.0),
        ("", ""),
        (" ", " "),
        ("a", "a"),
        (None, None),
        ([0, 1], [0.0, 1.0]),
        (array([1, 2, 3]), array([1, 2, 3])),
        (array([[1, 2], [3, 4]]), array([[1.0, 2.0], [3.0, 4.0]])),
        (zeros(0), []),
        (zeros(0), zeros(0)),
        (array([]), zeros(0)),
        (zeros(3), zeros(3)),
        (array([0, 0, 0]), zeros(3)),
        (array([]), []),
    ]

    small = 1e-7
    big = 1e-5

    within_1e6_abs_pairs = [
        (1, 1 + small),
        (1 + small, 1),
        (1, 1 - small),
        (1 - small, 1),
        (100000, 100000 - small),
        (-100000, -100000 - small),
        (-1, -1 + small),
        (-1, -1 - small),
        (0, small),
        (0, -small),
        (array([1, 2]), array([1, 2 + small])),
        (array([[1, 2], [3, 4]]), array([[1, 2 + small], [3, 4]])),
    ]

    within_1e6_rel_pairs = [
        (1, 1 + 1 * small),
        (1 + 1 * small, 1),
        (1, 1 - 1 * small),
        (1 - 1 * small, 1),
        (100000, 100000 - 100000 * small),
        (-100000, -100000 - 100000 * small),
        (-1, -1 + -1 * small),
        (-1, -1 - -1 * small),
        (array([1, 2]), array([1 + small, 2])),
        (
            array([[1000, 1000], [1000, 1000]]),
            array([[1000 + 1000 * small, 1000], [1000, 1000]]),
        ),
    ]

    outside_1e6_abs_pairs = [
        (1, 1 + big),
        (1 + big, 1),
        (1, 1 - big),
        (1 - big, 1),
        (100000, 100000 - big),
        (-100000, -100000 - big),
        (-1, -1 + big),
        (-1, -1 - big),
        (0, big),
        (0, -big),
        (1e7, 1e7 + 1),
        (array([1, 1]), array([1, 1 + big])),
        (array([[1, 1], [1, 1]]), array([[1, 1 + big], [1, 1]])),
    ]

    outside_1e6_rel_pairs = [
        (1, 1 + 1 * big),
        (1 + 1 * big, 1),
        (1, 1 - 1 * big),
        (1 - 1 * big, 1),
        (100000, 100000 - 100000 * big),
        (-100000, -100000 - 100000 * big),
        (-1, -1 + -1 * big),
        (-1, -1 - -1 * big),
        (1e-30, 1e-30 + small),
        (0, small),
        (1e5, 1e5 + 1),
        (array([1, 1]), array([1, 1 + 1 * big])),
    ]

    def test_assertNotEqual_None(self):
        """assertNotEqual should raise exception with two copies of None"""
        try:
            self.assertNotEqual(None, None)
        except:
            message = str(exc_info()[1])
            self.assertEqual(
                message, "Observed None and expected None: shouldn't test equal"
            )
        else:
            raise AssertionError(
                "unit_test.assertNotEqual failed on input %s and %s"
                % (repr(first), repr(second))
            )

    def test_assertNotEqual_numbers(self):
        """assertNotEqual should raise exception with integer and float zero"""
        try:
            self.assertNotEqual(0, 0.0)
        except:
            message = str(exc_info()[1])
            self.assertEqual(
                message, "Observed 0 and expected 0.0: shouldn't test equal"
            )
        else:
            raise AssertionError(
                "unit_test.assertNotEqual failed on input %s and %s"
                % (repr(first), repr(second))
            )

    def test_assertNotEqual_unequal(self):
        """assertNotEqual should not raise exception when values differ"""
        for first, second in self.unequal_pairs:
            try:
                self.assertNotEqual(first, second)
            except:
                raise AssertionError(
                    "unit_test.assertNotEqual failed on input %s and %s"
                    % (repr(first), repr(second))
                )

    def test_assertNotEqual_equal(self):
        """assertNotEqual should raise exception when values differ"""
        for first, second in self.equal_pairs:
            try:
                self.assertNotEqual(first, second)
            except:
                message = str(exc_info()[1])
                self.assertEqual(
                    message,
                    "Observed %s and expected %s: shouldn't test equal"
                    % (repr(first), repr(second)),
                )
            else:
                raise AssertionError(
                    "unit_test.assertNotEqual failed on input %s and %s"
                    % (repr(first), repr(second))
                )

    def test_assertEqual_None(self):
        """assertEqual should not raise exception with two copies of None"""
        try:
            self.assertEqual(None, None)
        except:
            raise AssertionError(
                "unit_test.assertEqual failed on input %s and %s"
                % (repr(first), repr(second))
            )

    def test_assertEqual_numbers(self):
        """assertEqual should not raise exception with integer and float zero"""
        try:
            self.assertEqual(0, 0.0)
        except:
            raise AssertionError(
                "unit_test.assertEqual failed on input %s and %s"
                % (repr(first), repr(second))
            )

    def test_assertEqual_unequal(self):
        """assertEqual should raise exception when values differ"""
        for first, second in self.unequal_pairs:
            try:
                self.assertEqual(first, second)
            except:
                message = str(exc_info()[1])
                self.assertEqual(
                    message, "Got %s, but expected %s" % (repr(first), repr(second))
                )
            else:
                raise AssertionError(
                    "unit_test.assertEqual failed on input %s and %s"
                    % (repr(first), repr(second))
                )

    def test_assertEqual_equal(self):
        """assertEqual should not raise exception when values test equal"""
        for first, second in self.equal_pairs:
            try:
                self.assertEqual(first, second)
            except:
                raise AssertionError(
                    "unit_test.assertEqual failed on input %s and %s"
                    % (repr(first), repr(second))
                )

    def test_assertEqual_nested_array(self):
        self.assertEqual([[1, 0], [0, 1]], [array([1, 0]), array([0, 1])])

    def test_assertEqual_shape_mismatch(self):
        """assertEqual should raise when obs and exp shapes mismatch"""
        obs = [1, 2, 3]
        exp = [1, 2, 3, 4]
        self.assertRaises(AssertionError, self.assertEqual, obs, exp)

    def test_assertFloatEqualAbs_equal(self):
        """assertFloatEqualAbs should not raise exception when values within eps"""
        for first, second in self.within_1e6_abs_pairs:
            try:
                self.assertFloatEqualAbs(first, second, eps=1e-6)
            except:
                raise AssertionError(
                    "unit_test.assertFloatEqualAbs failed on input %s and %s"
                    % (repr(first), repr(second))
                )

    def test_assertFloatEqualAbs_threshold(self):
        """assertFloatEqualAbs should raise exception when eps is very small"""
        for first, second in self.within_1e6_abs_pairs:
            try:
                self.assertFloatEqualAbs(first, second, 1e-30)
            except:
                message = str(exc_info()[1])
                diff = first - second
                exp = "True is not false : Got %s, but expected %s (diff was %s)" % (
                    repr(first),
                    repr(second),
                    repr(diff),
                )
                self.assertEqual(message, exp)
            else:
                raise AssertionError(
                    "unit_test.assertFloatEqualAbs failed on input %s and %s"
                    % (repr(first), repr(second))
                )

    def test_assertFloatEqualAbs_unequal(self):
        """assertFloatEqualAbs should raise exception when values differ by >eps"""
        for first, second in self.outside_1e6_abs_pairs:
            try:
                self.assertFloatEqualAbs(first, second)
            except:
                message = str(exc_info()[1])
                diff = first - second
                self.assertEqual(
                    message,
                    "True is not false : Got %s, but expected %s (diff was %s)"
                    % (repr(first), repr(second), repr(diff)),
                )
            else:
                raise AssertionError(
                    "unit_test.assertFloatEqualAbs failed on input %s and %s"
                    % (repr(first), repr(second))
                )

    def test_assertFloatEqualAbs_shape_mismatch(self):
        """assertFloatEqualAbs should raise when obs and exp shapes mismatch"""
        obs = [1, 2, 3]
        exp = [1, 2, 3, 4]
        self.assertRaises(AssertionError, self.assertFloatEqualAbs, obs, exp)

    def test_assertFloatEqualRel_equal(self):
        """assertFloatEqualRel should not raise exception when values within eps"""
        for first, second in self.within_1e6_rel_pairs:
            try:
                self.assertFloatEqualRel(first, second)
            except:
                raise AssertionError(
                    "unit_test.assertFloatEqualRel failed on input %s and %s"
                    % (repr(first), repr(second))
                )

    def test_assertFloatEqualRel_unequal(self):
        """assertFloatEqualRel should raise exception when eps is very small"""
        for first, second in self.within_1e6_rel_pairs:
            try:
                self.assertFloatEqualRel(first, second, 1e-30)
            except:
                message = str(exc_info()[1])
                diff = first - second
                self.assertEqual(
                    message,
                    "True is not false : Got %s, but expected %s (diff was %s)"
                    % (repr(first), repr(second), repr(diff)),
                )
            else:
                raise AssertionError(
                    "unit_test.assertFloatEqualRel failed on input %s and %s"
                    % (repr(first), repr(second))
                )

    def test_assertFloatEqualRel_unequal(self):
        """assertFloatEqualRel should raise exception when values differ by >eps"""
        for first, second in self.outside_1e6_rel_pairs:
            try:
                self.assertFloatEqualRel(first, second)
            except:
                message = str(exc_info()[1])
                diff = first - second
                self.assertEqual(
                    message,
                    "True is not false : Got %s, but expected %s (diff was %s)"
                    % (repr(first), repr(second), repr(diff)),
                )
            else:
                raise AssertionError(
                    "unit_test.assertFloatEqualRel failed on input %s and %s"
                    % (repr(first), repr(second))
                )

    def test_assertFloatEqualRel_shape_mismatch(self):
        """assertFloatEqualRel should raise when obs and exp shapes mismatch"""
        obs = [1, 2, 3]
        exp = [1, 2, 3, 4]
        self.assertRaises(AssertionError, self.assertFloatEqualRel, obs, exp)

    def test_assertFloatEqualList_equal(self):
        """assertFloatEqual should work on two lists of similar values"""
        originals = [0, 1, -1, 10, -10, 100, -100]
        modified = [i + 1e-7 for i in originals]
        try:
            self.assertFloatEqual(originals, modified)
            self.assertFloatEqual([], [])  # test empty lists as well
        except:
            raise AssertionError(
                "unit_test.assertFloatEqual failed on lists of similar values"
            )

    def test_assertFloatEqual_shape_mismatch(self):
        """assertFloatEqual should raise when obs and exp shapes mismatch"""
        obs = [1, 2, 3]
        exp = [1, 2, 3, 4]
        self.assertRaises(AssertionError, self.assertFloatEqual, obs, exp)

    def test_assertFloatEqualList_unequal(self):
        """assertFloatEqual should fail on two lists of dissimilar values"""
        originals = [0, 1, -1, 10, -10, 100, -100]
        modified = [i + 1e-5 for i in originals]
        try:
            self.assertFloatEqual(originals, modified)
        except:
            pass
        else:
            raise AssertionError(
                "unit_test.assertFloatEqual failed on lists of dissimilar values"
            )

    def test_assertFloatEqual_mixed(self):
        """assertFloatEqual should work on equal lists of mixed types."""
        first = [i[0] for i in self.equal_pairs]
        second = [i[1] for i in self.equal_pairs]
        self.assertFloatEqual(first, second)

    def test_assertFloatEqualAbs_mixed(self):
        first = [i[0] for i in self.equal_pairs]
        second = [i[1] for i in self.equal_pairs]
        """assertFloatEqualAbs should work on equal lists of mixed types."""
        self.assertFloatEqualAbs(first, second)

    def test_assertFloatEqualRel_mixed(self):
        first = [i[0] for i in self.equal_pairs]
        second = [i[1] for i in self.equal_pairs]
        """assertFloatEqualRel should work on equal lists of mixed types."""
        self.assertFloatEqualRel(first, second)

    def test_assertFloatEqual_mixed_unequal(self):
        """assertFloatEqual should work on unequal lists of mixed types."""
        first = [i[0] for i in self.unequal_pairs]
        second = [i[1] for i in self.unequal_pairs]
        self.assertRaises(AssertionError, self.assertFloatEqual, first, second)

    def test_assertFloatEqualAbs_mixed(self):
        """assertFloatEqualAbs should work on lists of mixed types."""
        first = [i[0] for i in self.unequal_pairs]
        second = [i[1] for i in self.unequal_pairs]
        self.assertRaises(AssertionError, self.assertFloatEqualAbs, first, second)

    def test_assertFloatEqualRel_mixed(self):
        """assertFloatEqualRel should work on lists of mixed types."""
        first = [i[0] for i in self.unequal_pairs]
        second = [i[1] for i in self.unequal_pairs]
        self.assertRaises(AssertionError, self.assertFloatEqualRel, first, second)

    def test_assertIsProb_None(self):
        """assertIsProb should raise when compared against None"""
        self.assertRaises(AssertionError, self.assertIsProb, None)

    def test_assertIsProb_numbers_true(self):
        """assertIsProb should pass when compared against valid numbers"""
        self.assertIsProb(0)
        self.assertIsProb(1)

    def test_assertIsProb_numbers_false(self):
        """assertIsProb should raise when compared against invalid numbers"""
        self.assertRaises(AssertionError, self.assertIsProb, -1)
        self.assertRaises(AssertionError, self.assertIsProb, 2)

    def test_assertIsProb_numbers_list_true(self):
        """assertIsProb should pass when all elements are probs"""
        observed = [0, 1, 0]
        self.assertIsProb(observed)

    def test_assertIsProb_numbers_list_false(self):
        """assertIsProb should raise when any element is not a prob"""
        observed = [-2, -4, 3]
        self.assertRaises(AssertionError, self.assertIsProb, observed)

    def test_assertIsProb_float_true(self):
        """assertIsProb should pass when compared against valid numbers"""
        self.assertIsProb(0.0)
        self.assertIsProb(1.0)

    def test_assertIsProb_float_false(self):
        """assertIsProb should raise when compared against invalid numbers"""
        self.assertRaises(AssertionError, self.assertIsProb, -1.0)
        self.assertRaises(AssertionError, self.assertIsProb, 2.0)

    def test_assertIsProb_float_list_true(self):
        """assertIsProb should pass when all elements are probs"""
        observed = [0.0, 1.0, 0.0]
        self.assertIsProb(observed)

    def test_assertIsProb_float_list_false(self):
        """assertIsProb should raise when any element is not a prob"""
        observed = [-2.0, -4.0, 3.0]
        self.assertRaises(AssertionError, self.assertIsProb, observed)

    def test_assertIsProb_mixed_list_true(self):
        """assertIsProb should pass when all elements are probs"""
        observed = [0.0, 1, 0.0]
        self.assertIsProb(observed)

    def test_assertIsProb_mixed_list_false(self):
        """assertIsProb should raise when any element is not a prob"""
        observed = [-2.0, -4, 3.0]
        self.assertRaises(AssertionError, self.assertIsProb, observed)

    def test_assertIsProb_numpy_array_true(self):
        """assertIsProb should pass when all elements are probs"""
        observed = array([0.0, 0.4, 0.8])
        self.assertIsProb(observed)

    def test_assertIsProb_numpy_array_true(self):
        """assertIsProb should pass when all elements are probs"""
        observed = array([0.0, -0.4, 0.8])
        self.assertRaises(AssertionError, self.assertIsProb, observed)

    def test_assertSimilarMeans_one_obs_true(self):
        """assertSimilarMeans should pass when p > pvalue"""
        obs = [5]
        expected = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
        self.assertSimilarMeans(obs, expected)
        self.assertSimilarMeans(obs, expected, pvalue=0.25)
        self._set_suite_pvalue(0.10)
        self.assertSimilarMeans(obs, expected)

    def test_assertSimilarMeans_one_obs_false(self):
        """assertSimilarMeans should raise when p < pvalue"""
        obs = [5]
        expected = [0.001, 0.009, 0.00012]
        self.assertRaises(AssertionError, self.assertSimilarMeans, obs, expected)
        self.assertRaises(AssertionError, self.assertSimilarMeans, obs, expected, 0.1)
        self._set_suite_pvalue(0.001)
        self.assertRaises(AssertionError, self.assertSimilarMeans, obs, expected)

    def test_assertSimilarMeans_twosample_true(self):
        """assertSimilarMeans should pass when p > pvalue"""
        obs = [4, 5, 6]
        expected = [1, 2, 3, 4, 5, 6, 7, 8, 9]
        self.assertSimilarMeans(obs, expected)
        self.assertSimilarMeans(obs, expected, pvalue=0.25)
        self._set_suite_pvalue(0.10)
        self.assertSimilarMeans(obs, expected)

    def test_assertSimilarMeans_twosample_false(self):
        """assertSimilarMeans should raise when p < pvalue"""
        obs = [1, 2, 3]
        expected = [6, 7, 8, 9, 10, 11, 12, 13, 14]
        self.assertRaises(AssertionError, self.assertSimilarMeans, obs, expected)
        self.assertRaises(AssertionError, self.assertSimilarMeans, obs, expected, 0.1)
        self._set_suite_pvalue(0.001)
        self.assertRaises(AssertionError, self.assertSimilarMeans, obs, expected)

    def test_assertSimilarFreqs_true(self):
        """assertSimilarFreqs should pass when p > pvalue"""
        observed = [2, 2, 3, 2, 1, 2, 2, 2, 2]
        expected = [2, 2, 2, 2, 2, 2, 2, 2, 2]
        self.assertSimilarFreqs(observed, expected)
        self.assertSimilarFreqs(observed, expected, pvalue=0.25)
        self._set_suite_pvalue(0.10)
        self.assertSimilarFreqs(observed, expected)

    def test_assertSimilarFreqs_false(self):
        """assertSimilarFreqs should raise when p < pvalue"""
        observed = [10, 15, 20, 10, 12, 12, 13]
        expected = [100, 50, 10, 20, 700, 2, 100]
        self.assertRaises(AssertionError, self.assertSimilarFreqs, observed, expected)
        self.assertRaises(
            AssertionError, self.assertSimilarFreqs, observed, expected, 0.2
        )
        self._set_suite_pvalue(0.001)
        self.assertRaises(AssertionError, self.assertSimilarFreqs, observed, expected)

    def test_assertSimilarFreqs_numpy_array_true(self):
        """assertSimilarFreqs should pass when p > pvalue"""
        observed = array([2, 2, 3, 2, 1, 2, 2, 2, 2])
        expected = array([2, 2, 2, 2, 2, 2, 2, 2, 2])
        self.assertSimilarFreqs(observed, expected)
        self.assertSimilarFreqs(observed, expected, pvalue=0.25)
        self._set_suite_pvalue(0.10)
        self.assertSimilarFreqs(observed, expected)

    def test_assertSimilarFreqs_numpy_array_false(self):
        """assertSimilarFreqs should raise when p < pvalue"""
        observed = array([10, 15, 20, 10, 12, 12, 13])
        expected = array([100, 50, 10, 20, 700, 2, 100])
        self.assertRaises(AssertionError, self.assertSimilarFreqs, observed, expected)
        self.assertRaises(
            AssertionError, self.assertSimilarFreqs, observed, expected, 0.2
        )
        self._set_suite_pvalue(0.001)
        self.assertRaises(AssertionError, self.assertSimilarFreqs, observed, expected)

    def test_set_suite_pvalue(self):
        """Should set the suite pvalue"""
        # force stats to fail
        self._set_suite_pvalue(0.99)
        obs = [2, 5, 6]
        exp = [1, 2, 3, 4, 5, 6, 7, 8, 9]
        self.assertRaises(AssertionError, self.assertSimilarMeans, obs, exp)

        # force stats to pass
        self._set_suite_pvalue(0.01)
        self.assertSimilarMeans(obs, exp)

    def test_assertSameObj_true(self):
        """assertSameObj should pass when 'a is b'"""
        self.assertIs("foo", "foo")
        self.assertIs(None, None)
        bar = lambda x: 5
        self.assertIs(bar, bar)

    def test_assertSameObj_false(self):
        """assertSameObj should raise when 'a is not b'"""
        self.assertRaises(AssertionError, self.assertIs, "foo", "bar")
        self.assertRaises(AssertionError, self.assertIs, None, "bar")
        self.assertRaises(AssertionError, self.assertIs, lambda x: 5, lambda y: 6)

    def test_assertNotSameObj_true(self):
        """assertNotSameObj should pass when 'a is not b'"""
        self.assertIsNot("foo", "bar")
        self.assertIsNot(None, 5)
        self.assertIsNot(lambda x: 5, lambda y: 6)

    def test_assertNotSameObj_false(self):
        """assertSameObj should raise when 'a is b'"""
        self.assertRaises(AssertionError, self.assertIsNot, "foo", "foo")
        self.assertRaises(AssertionError, self.assertIsNot, None, None)
        bar = lambda x: 5
        self.assertRaises(AssertionError, self.assertIsNot, bar, bar)


if __name__ == "__main__":
    main()
